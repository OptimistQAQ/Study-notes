## Pandas方法
使用pandas首先要导入pandas包。

```python
import pandas as pd  //标准的导入pandas的代码
```


### 读入csv文件
```python
trainData = pd.read_csv("./Data/train.csv") //
./Data/   表示路径，train表示文件名
```
### 标题获取文件中的前5行数据

```python
trainData.head() //
.head()是pandas中的一个方法，可以获取文件中的前5行数据
```
![在这里插入图片描述](https://img-blog.csdnimg.cn/20190521193906796.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80Mzg5NTQ4Mg==,size_16,color_FFFFFF,t_70)
### info() 迅速获取数据描述

```python
trainData.info()  // 方法就不具体介绍了   下面给出运行结果

//////////////    运行结果
<class 'pandas.core.frame.DataFrame'>
RangeIndex: 891 entries, 0 to 890
Data columns (total 10 columns):
Pclass      891 non-null int64
Name        891 non-null object
Sex         891 non-null object
Age         714 non-null float64
SibSp       891 non-null int64
Parch       891 non-null int64
Ticket      891 non-null object
Fare        891 non-null float64
Cabin       204 non-null object
Embarked    889 non-null object
dtypes: float64(2), int64(3), object(5)
memory usage: 69.7+ KB
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190915110156432.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80Mzg5NTQ4Mg==,size_16,color_FFFFFF,t_70)
### .drop( , , )
```python
#删除name
allData.drop("Name",axis=1,inplace=True)  //
第一个参数为要删除的内容，第二第三个参数的形式固定
```
### 替换文件中的内容

```python
#可以考虑替换为出现的次数
allData['SibSp'].value_counts()   // 
替换SibSp中缺失的数据为出现的次数

///////////////运行结果
0    891
1    319
2     42
4     22
3     20
8      9
5      6
Name: SibSp, dtype: int64
```
### 合并两个文件中的内容

```python
allData = pd.concat([trainData,testData],axis=0,ignore_index=True)  
//第一个参数为两个文件名，第二第三个参数格式相同
```

###  pd.set_option() 设置指定的值

```python
pd.setoption('max_rows',7)  //////设置最大的行数
```


###  value_counts()   获取每个值出现的次数
```python
trainData['Pclass'].value_counts()
```

###  fillna()   用指定方法填充

```python
age = trainData['Age']
age = age.fillna(0)   ////将年龄用0来填充
```

###  客串seaborn中的一个方法  distplot(age)  画出age的树状图

```python
sns.distplot(age)
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190915112502222.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80Mzg5NTQ4Mg==,size_16,color_FFFFFF,t_70)

###  describe()  简要显示数据的数字特征

```python
allData['Fare'].describe()
```

![在这里插入图片描述](https://img-blog.csdnimg.cn/20190915113352696.PNG?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80Mzg5NTQ4Mg==,size_16,color_FFFFFF,t_70)

​	

小豪能力有限，还在学习中，未完待续……