#  这里给出小豪的实战项目github地址

>  https://github.com/OptimistQAQ/CoolWeather 

# 备注：
在这里应该首先告诫读者，当你的程序出现报错的时候，很大一定程度上是你的代码出现了问题，比如：代码写错了、少写了、多写了等等都会引起程序出现问题。极少部分情况是因为书的年代久远，有些东西更新换代了，会导致你的程序出现问题。那么在这个时候，就需要多看几篇博客，多去请教那些比你厉害的学长。

# 在这里要给读者一些建议
照着书敲代码的时候不存在什么逻辑问题，因为那又不是你的逻辑，只存在细心不细心的问题，***不要自以为是的想当然***，这才是最重要的，当然在照着书写代码的时候，你是会学到读者的逻辑的，这也是一种学习。只要认真一点，就能少走很多坑！

# 我的问题

 1. **遍历的城市信息无法显示**

```java
package com.example.administrator.coolweather;

import android.app.ProgressDialog;
import android.content.Intent;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import com.example.administrator.coolweather.db.City;
import com.example.administrator.coolweather.db.County;
import com.example.administrator.coolweather.db.Province;
import com.example.administrator.coolweather.util.HttpUtil;
import com.example.administrator.coolweather.util.Utility;

import org.litepal.crud.DataSupport;

import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

import okhttp3.Call;
import okhttp3.Callback;
import okhttp3.Response;

public class ChooseAreaFragment extends Fragment {

    public static final int LEVEL_PROVINCE  = 0;
    public static final int LEVEL_CITY = 1;
    public static final int LEVEL_COUNTY = 2;

    private ProgressDialog progressDialog;

    private TextView titleText;
    private Button backButton;
    private ListView listView;
    private ArrayAdapter<String> adapter;
    private List<String> dataList = new ArrayList<>();



    /*
    **省列表
     */
    private List<Province> provinceList;

    /*
    ****市列表
     */
    private List<City> cityList;

    /*
    **县列表
     */
    private List<County> countyList;

    /*
    ***选中的省份
     */
    private Province selectedProvince;

    /*
    ****选中的城市
     */
    private City selectedCity;

    /*
    *****当前选中的级别
     */
    private int currentLevel;

    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container,
                             Bundle savedInstanceState) {

        View view = inflater.inflate(R.layout.choose_area,container,false);
        titleText = (TextView) view.findViewById(R.id.title_text);
        backButton = (Button) view.findViewById(R.id.back_button);
        listView = (ListView) view.findViewById(R.id.list_view);
        adapter = new ArrayAdapter<>(getContext(),android.R.layout.simple_list_item_1,
                dataList);
        listView.setAdapter(adapter);
        return view;
    }
    @Override
    public void onActivityCreated(Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        listView.setOnItemClickListener(new AdapterView.OnItemClickListener() {
            @Override
            public void onItemClick(AdapterView<?> parent, View view, int position,
                                    long id) {
                if(currentLevel == LEVEL_PROVINCE){
                    selectedProvince = provinceList.get(position);
                    queryCities();
                }
                else if(currentLevel == LEVEL_CITY){
                    selectedCity = cityList.get(position);
                    queryCounties();
                }
                else if(currentLevel == LEVEL_COUNTY){
                    String weatherId = countyList.get(position).getWeatherId();

                    if(getActivity() instanceof MainActivity) {
                        Intent intent = new Intent(getActivity(), WeatherActivity.class);
                        intent.putExtra("weather_id", weatherId);
                        startActivity(intent);
                        getActivity().finish();
                    }
                    else if(getActivity() instanceof WeatherActivity){
                        WeatherActivity activity = (WeatherActivity) getActivity();
                        activity.drawerLayout.closeDrawers();
                        activity.swipeRefresh.setRefreshing(true);
                        activity.requestWeather(weatherId);
                    }
                }
            }
        });

        backButton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if(currentLevel == LEVEL_COUNTY){
                    queryCities();
                }
                else if(currentLevel == LEVEL_CITY){
                    queryProvinces();
                }
            }
        });
        queryProvinces();
    }

    /*
    *******查询全国所有的省，优先从数据库中查，如果没有再到服务器上查询
     */
    private void queryProvinces(){
        titleText.setText("中国");
        backButton.setVisibility(View.GONE);
        provinceList = DataSupport.findAll(Province.class);
        if(provinceList.size() > 0){
            dataList.clear();
            for(Province province : provinceList){
                dataList.add(province.getProvinceName());
            }
            adapter.notifyDataSetChanged();
            listView.setSelection(0);
            currentLevel = LEVEL_PROVINCE;
        }
        else{
            String address = "http://guolin.tech/api/china";
            queryFromServer(address,"province");
        }
    }

    /*
    ***查询选中省内所有的市，优先从数据库中查，如果没有再到服务器上查询
     */
    private void queryCities(){
        titleText.setText(selectedProvince.getProvinceName());

        backButton.setVisibility(View.VISIBLE);
        cityList = DataSupport.where("provinceid = ?",String.valueOf(
                selectedProvince.getId())).find(City.class);
        if(cityList.size() > 0){
            dataList.clear();
            for(City city : cityList){
                dataList.add(city.getCityName());
            }
            adapter.notifyDataSetChanged();
            listView.setSelection(0);
            currentLevel = LEVEL_CITY;
        }
        else{
            int provinceCode = selectedProvince.getProvinceCode();
            String address = "http://guolin.tech/api/china/" + provinceCode;
            queryFromServer(address,"city");
        }

    }

    /*
    *******查询选中市内所有的县，优先从数据库中查，如果没有再到服务器上查询
     */
    private void queryCounties(){

        titleText.setText(selectedCity.getCityName());
        backButton.setVisibility(View.VISIBLE);
        countyList = DataSupport.where("cityid = ?",String.valueOf(
                selectedCity.getId())).find(County.class);
        if(countyList.size() > 0){
            dataList.clear();
            for(County county : countyList){
                dataList.add(county.getCountyName());
            }
            adapter.notifyDataSetChanged();
            listView.setSelection(0);
            currentLevel = LEVEL_COUNTY;
        }
        else{
            int provinceCode = selectedProvince.getProvinceCode();
            int cityCode = selectedCity.getCityCode();
            String address = "http://guolin.tech/api/china/"+provinceCode+"/"+cityCode;
            queryFromServer(address,"county");
        }
    }

    /*
    ******根据传入的地址和类型从服务器上查询省市县数据
     */
    private void queryFromServer(String address,final String type){
        showProgressDialog();
        HttpUtil.sendOkHttpRequest(address, new Callback() {
            @Override
            public void onFailure(Call call, IOException e) {
                //通过runOnUiThread()方法回到主线程处理逻辑
                getActivity().runOnUiThread(new Runnable() {
                    @Override
                    public void run() {
                        closeProgressDialog();
                        Toast.makeText(getContext(),"加载失败",Toast.LENGTH_SHORT).show();
                    }
                });
            }

            @Override
            public void onResponse(Call call, Response response) throws IOException {
                String responseText = response.body().string();
                boolean result = false;
                if("province".equals(type)){
                    result = Utility.handleProvinceResponse(responseText);
                }
                else if("city".equals(type)){
                    result = Utility.handleCityResponse(responseText,
                            selectedProvince.getId());
                }
                else if("county".equals(type)){
                    result = Utility.handleCountyResponse(responseText,
                            selectedCity.getId());
                }

                if(result){
                    getActivity().runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            closeProgressDialog();
                            if("province".equals(type)){
                                queryProvinces();
                            }
                            else if("city".equals(type)){
                                queryCities();
                            }
                            else if("county".equals(type)){
                                queryCounties();
                            }
                        }
                    });
                }
            }
        });
    }



    /*
     *****显示进度对话框
     */

    private void showProgressDialog(){
        if(progressDialog == null){
            progressDialog = new ProgressDialog(getActivity());
            progressDialog.setMessage("正在加载...");
            progressDialog.setCanceledOnTouchOutside(false);
        }
        progressDialog.show();
    }



    /*
    ***关闭进度对话框
     */

    private void closeProgressDialog(){
        if(progressDialog != null){
            progressDialog.dismiss();
        }
    }

}




```

像这种情况就不是因为你的代码出现问题，因为你的代码没有问题，那么问题在哪呢？
https://blog.csdn.net/yonbor605/article/details/82223882   这个网址会给你想要的答案，并得到解决。

/////////   新版本的手机模拟器不能访问Http协议，需要设置请求，详情见博客。
https://blog.csdn.net/yonbor605/article/details/82223882