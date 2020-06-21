# C++实验一

[TOC]

## 实验名称

> **类的继承与派生**

## 实验题目

> *分别定义Teacher(教师)类和Cadre（干部）类，采用多重继承方式由这两个类派生出新类Teacher_Cadre（教师兼干部）。要求：* 
>
> *（1）在两个基类中都包含姓名、年龄、性别、地址、电话等数据成员。* 
>
> *（2）在Teacher类中还包含数据成员title(职称)，在Cadre类中还包含数据成员post（职务），在Teacher_Cadre类中还包含数据成员wages(工资)。* 
>
> *（3）对两个基类中的姓名、年龄、性别、地址、电话等数据成员用相同的名字，在引用这些数据成员时，指定作用域。* 
>
> *（4）在类体中声明成员函数，在类外定义成员函数。* 
>
> *（5）在派生类Teacher_Cadre的成员函数show中调用Teacher类中的display函数，输出姓名、年龄、性别、职称、地址、电话，然后再用cout语句输出职务与工资。*

## 源代码

```c++
class Teacher {
public:
	Teacher(string name, int age, char sex, string addr, int tel, string title) {
		this->name = name;
		this->age = age;
		this->sex = sex;
		this->addr = addr;
		this->tel = tel;
		this->title = title;
	}
	void display() {
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
		cout << "sex: " << sex << endl;
		cout << "title: " << title << endl;
		cout << "address: " << addr << endl;
		cout << "tel: " << tel << endl;
	}
protected:
	string name;
	int age;
	char sex;
	string addr;
	int tel;
	string title;
};

class Cadre {
public:
	Cadre(string name, int age, char sex, string addr, int tel, string post) {
		this->name = name;
		this->age = age;
		this->sex = sex;
		this->addr = addr;
		this->tel = tel;
		this->post = post;
	}
	void display1() {
		cout << "name: " << name << endl;
		cout << "age: " << age << endl;
		cout << "sex: " << sex << endl;
		cout << "post: " << post << endl;
		cout << "address: " << addr << endl;
		cout << "tel: " << tel << endl;
	}
protected:
	string name;
	int age;
	char sex;
	string addr;
	int tel;
	string post;
};
//继承的思想
class Teacher_Cadre : public Teacher, public Cadre {
public:
	Teacher_Cadre(string nam, int a, char s, string ad, int te, string tit, string po, double w):
		Teacher(nam, a, s, ad, te, tit), Cadre(nam, a, s, ad, te, po), wage(w){}
	void show() {
		display();
		cout << "post: " << post << endl;
		cout << "wage: " << wage << endl;
	}
private:
	double wage;
};
int main()
{
	Teacher_Cadre person("LiSi", 20, 'M', "ShanXi", 18070041, "professor", "assitant", 10001);
	person.show();
	system("pause");
	return 0;
}
```

