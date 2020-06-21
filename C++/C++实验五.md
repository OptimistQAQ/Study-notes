# C++实验五

[TOC]

## 实验名称

> **静态成员与常成员的使用**

## 实验题目

> *编程实现以下功能:* 
>
> *（1）某商店经销一种货物，货物成箱购进，成箱卖出，购进和卖出时以重量为单位，各箱的重量不一样，因此，商店需要记录下目前库存的货物的总重量，现在要求设计一个Goods类并使用静态成员来模拟商店货物购进和卖出的情况；*
>
> *（2）为上面的Goods类添加一个常数据成员（货物名称），并对货物名称进行初始化；*
>
> *（3）将前面已定义的某些成员函数改写为常成员函数，观察是否该类中所有的成员函数是否都可设定为常成员函数。*

## 源代码

```c++
class Goods {
private:
	static double totalWeight;
	double weight;
	const string name = "Goods name";
public:
	Goods(double w) :weight(w){}
	~Goods() {
	}
	/*void add(double n) {
		totalWeight += n;
	}*/
	
	//修改为常函数
	const void add(double n) {
		totalWeight += n;
	}
	//修改为常函数
	const void reduce(double n) {
		totalWeight -= n;
	}
	//修改为常函数
	const void get_totalWeight() {
		cout << "货物名称：" << name << endl;
		cout << "当前货物总量为：\n";
		cout << totalWeight << endl;
	}
};

double Goods::totalWeight = 0.0;

int main()
{
	int flag;
	double w;
	while (1) {
		cout << "输入1表示买货， 输入2表示卖货，输入0退出: \n";
		cin >> flag;
		if (flag == 0)
			break;
		else if (flag == 1) {
			cout << "请输入进货的weight：\n";
			cin >> w;
			Goods good = Goods(w);
			good.add(w);
			good.get_totalWeight();
		}
		else {
			cout << "请输入卖出的weight：\n";
			cin >> w;
			Goods good = Goods(w);
			good.reduce(w);
			good.get_totalWeight();
		}
	}
	system("pause");
	return 0;
}
```

