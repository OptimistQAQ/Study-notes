#include<iostream>
#include<string>
#include<stdio.h>
#include<algorithm>
#include<Windows.h>
#include<iomanip>
#include<fstream>

using namespace std;

class Staff {
private:
	int id;
	string name;
	int age;
	double pay;
public:
	Staff(int n, string s, int a, double p) {
		id = n;
		name = s;
		age = a;
		pay = p;
	}
	Staff(){}
	int getid() {
		return id;
	}
	void display() {
		cout << "职工号：" << id << "姓名：" << name << "年龄：" << age << "工资：" << pay << endl;
	}
	void input() {
		cout << "id: ";
		cin >> id;
		cout<< "name: ";
		cin >> name;
		cout<< "age: ";
		cin >> age;
		cout<< "pay: ";
		cin >> pay;
	}
};

class File {
private:
	char *filename;
public:
	File(char *p) :filename(p) {}

	void writeFile(Staff *pstaff, int n) {
		ofstream iofile(filename, ios::in | ios::out | ios::binary);
		if (!iofile) {
			cerr << "open error! " << endl;
			abort();  //退出
		}
		for (int i = 0; i < n; i++) {
			iofile.write((char *)&pstaff[i], sizeof(pstaff[i]));
		}
		iofile.close();
	}

	void writeFile(Staff *pstaff) {
		ofstream iofile(filename, ios::out | ios::app);
		if (!iofile) {
			cerr << "open error! " << endl;
			abort();
		}
		iofile.seekp(0, ios::end);
		iofile.write((char *)&pstaff, sizeof(Staff));
		iofile.close();
	}

	void readFile(Staff *pstaff, int n) {
		ifstream iffile(filename, ios::in | ios::out | ios::binary);
		if (!iffile) {
			cerr << "open error! " << endl;
			abort();
		}
		for (int i = 0; i < n; i++) {
			iffile.read((char *)&pstaff[i], sizeof(pstaff[i]));
		}
		iffile.close();
	}

	void searchFile(int n) {
		bool label = false;
		ifstream iffile(filename, ios::in | ios::binary);
		if (!iffile) {
			cout << "open error! " << endl;
			abort();
		}
		Staff s;
		while (!iffile.eof()) {
			iffile.read((char *)&s, sizeof(s));
			if (s.getid() == n) {
				label = true;
				break;
			}
		}
		if (label) {
			int m = iffile.tellg();  // 得到输入文件位置标志当前位置
			cout << n << "is the" << m / sizeof(Staff) << endl;
			s.display();
		}
		else {
			cout << "-1" << endl;
			iffile.close();
		}
	}
};

int main()
{
	Staff sta[7] = {
		Staff(111, "Zhao", 34, 1220),
		Staff(112, "Qian", 23, 6740),
		Staff(113, "Sun", 20, 5000),
		Staff(114, "Zhang", 22, 6000),
		Staff(115, "Zhou", 21, 4000)
	};
	char f[20] = "staff.dat";
	File file(f);
	file.writeFile(sta, 5);
	cout << "Please input data you want to insert: " << endl;
	Staff s[2];
	for (int i = 0; i < 1; i++) {
		s[i].input();
		file.writeFile(&s[i]);
	}
	Staff s2[6];
	file.readFile(s2, 6);
	for (int i = 0; i < 6; i++)
		s2[i].display();
	cout << "Enter number you want to search, enter 0 to stop. ";
	int num;
	cin >> num;
	while (num) {
		file.searchFile(num);
		cout << "Enter number you want to search, enter 0 to stop. ";
		cin >> num;
	}
	system("pause");
	return 0;
}