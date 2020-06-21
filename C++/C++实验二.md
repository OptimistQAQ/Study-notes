# C++实验二

[TOC]

## 实验名称

> **多态与重载**

## 实验题目

> *定义Point类，有坐标x，y两个成员变量；对Point类重载“++”(自增)、“--”(自减)运算符，实现对坐标值的改变。*

## 源代码

```c++
class Point {
private:
	int x;
	int y;
public:
	Point(int _x = 0, int _y = 0) :x(_x), y(_y){}
	Point operator ++() {
		return Point(x + 1, y + 1);
	}
	Point operator --() {
		return Point(x - 1, y - 1);
	}
	void print() {
		cout << "(" << x << ", " << y << ")" << endl;
	}
};
int main()
{
	Point p(6, 7);
	Point p0(70, 60);
	cout << "原始坐标：" << endl;
	p.print();
	cout << "增加以后的坐标：" << endl;
	p = p.operator++();
	p.print();
	cout << "原始坐标：" << endl;
	p0.print();
	cout << "自减以后的坐标：" << endl;
	p0 = p0.operator--();
	p0.print();
	system("pause");
	return 0;
}
```

