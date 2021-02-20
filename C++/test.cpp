#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include<conio.h>
#include<iostream>

using namespace std;

class Student
{
private:
	int num;
	int score;
public:
	void setdata(){
		cin >> num;
		cin >> score;
	}

	void display(){
		cout << "num = " << num << endl;
		cout << "score = " << score << endl;
	}
};

Student s1, s2;

int main()
{
	s1.setdata();
	s1.display();
	s2.setdata();
	s2.display();
	return 0;
}