# C++实验四

[TOC]

## 实验名称

> **类的定义与使用**

## 实验题目

> *编制程序完成以下功能：*
>
> *（1）定义一个CDate类，包含年(year)、月(month)、日(day)等属性，有三个公有成员函数：SetDate来设置日期、AddOneDay来对日期进行加1天的操作、print来输出日期；*
>
> *（2）对构造函数或成员函数进行重载；*
>
> *（3）设置构造函数或成员函数的缺省参数*
>
> *（4）观察构造函数和析构函数的调用顺序；*
>
> *（5）观察具有不同访问属性的成员的访问方式。*

## 源代码

```c++
class CDate {
private:
	int year;
	int month;
	int day;
public:
	CDate() {}
	CDate(int y, int m = 1, int d = 1):year(y), month(m), day(d) {}
	
	~CDate() {
		cout << "析构！" << endl;
	}

	void setDate() {
		cin >> year;
		cin >> month;
		cin >> day;
	}
	void addOneDay() {
		if ((year % 4) == 0 && month == 2 && day == 29) {
			month++;
			day = 1;
		}
		else if (month == 2 && day == 28) {
			month++;
			day = 1;
		}
		else if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 30) {
			month++;
			day = 1;
		}
		else if (day == 31 && month == 12) {
			year++;
			month = 1;
			day = 1;
		}
		else if (day == 31) {
			month++;
			day = 1;
		}
		else {
			day++;
		}
	}
	void print() {
		cout << year << "年" << month << "月" << day << "日" << endl;
	}
};
int main()
{
	CDate date = CDate();
	cout << "请输入合法日期：\n";
	date.setDate();
	date.addOneDay();
	date.print();
	cout << "缺省参数验证: " << endl;
	CDate date1 = CDate(2020);
	CDate date2 = CDate(2020, 4, 30);
	date1.addOneDay();
	date1.print();
	date2.addOneDay();
	date2.print();
	system("pause");
	return 0;
}
```

