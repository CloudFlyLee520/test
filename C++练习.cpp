//P309 例8-1
//复数类加减法运算重载为成员函数形式
//#define FuShu
#ifdef FuShu
#include <iostream>
using namespace std;

class Complex {
public:
	Complex(double r = 0.0, double i = 0.0) :real(r), imag(i) {}
	Complex operator+ (const Complex &c2)const;
	Complex operator- (const Complex& c2)const;
	void display()const;

private:
	double real;
	double imag;

};

Complex Complex::operator+(const Complex &c2)const {
	return Complex(real + c2.real, imag + c2.imag);
}
Complex Complex::operator-(const Complex& c2)const {
	return Complex(real - c2.real, imag - c2.imag);
}

void Complex::display()const {
	cout << "{" << real << "," << imag << "}" << endl;
}

int main()
{
	Complex c1(5, 4), c2(2, 10), c3;
	cout << "c1="; c1.display();
	cout << "c2="; c2.display();
	c3 = c1 - c2;
	cout << "c3=c1-c2="; c3.display();
	c3 = c1 + c2;
	cout << "c3=c1+c2="; c3.display();
	return 0;
}
#endif


//P311 例8-2
//将单目运算符“++”重载为成员函数形式
//#define JiaJia
#ifdef JiaJia
#include <iostream>
using namespace std;

class Clock {
public:
	Clock(int hour = 0, int minute = 0, int second = 0);
	void showTime()const;
	Clock& operator++();
	Clock operator++(int);
private:
	int hour, minute, second;
};

Clock::Clock(int hour, int minute, int second) {
	if (0 <= hour && hour < 24 && 0 <= minute && minute < 60 && 0 <= second && second < 60) {
		this->hour = hour;
		this->minute = minute;
		this->second = second;
	}
	else
		cout << "Time error!" << endl;
}

void Clock::showTime()const {
	cout << hour << ":" << minute << ":" << second << endl;
}
Clock& Clock::operator++() {
	second++;
	if (second >= 60) {
		second -= 60;
		minute++;
		if (minute >= 60) {
			minute -= 60;
			hour = (hour + 1) % 24;
		}
	}
	return*this;
}
Clock Clock::operator++(int) {
	Clock old = *this;
	++(*this);
	return old;
}

int main() {
	Clock myClock(23, 59, 59);
	cout << "First time output: ";
	myClock.showTime();

	cout << "Show myClock++:    ";
	(myClock++).showTime();

	cout << "++Show myClock:    ";
	(++myClock).showTime();

	return 0;
}



#endif


//
//虚函数
//#define VirtualFunction
#ifdef VirtualFunction

#include <iostream>
#include <string>
using namespace std;
//基类People
class People {
public:
	People(string name, int age);
	void display();
protected:
	string m_name;
	int m_age;
};

People::People(string name, int age) : m_name(name), m_age(age) {}
void People::display() {
	cout << m_name << "今年" << m_age << "岁了，是个无业游民。" << endl;
}
//派生类Teacher
class Teacher : public People {
public:
	Teacher(string name, int age, int salary);
	void display();
private:
	int m_salary;
};
Teacher::Teacher(string name, int age, int salary) : People(name, age), m_salary(salary) {}
void Teacher::display() {
	cout << m_name << "今年" << m_age << "岁了，是一名教师，每月有" << m_salary << "元的收入。" << endl;
}
int main() {
	People* p = new People("王志刚", 23);
	p->display();
	p = new Teacher("赵宏佳", 45, 8200);
	p->display();
	return 0;
}

#endif 


//将浮点型转换为字符串
#ifdef DoubleToString

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class A
{
private:
	double X = 335.058;
	double Y = 19.8463;
	double Z = 12.2274;
public:
	char* AA();

};

char * A::AA()
{
	char res[100] = {0};
	stringstream ss;

	ss << X << "," << Y << "," << Z;
	ss >> res;
	//cout << res;
	return res;
}

class B :public A 
{
private:
public:




};


int main() {
	B b;
	cout << b.AA(); 
}





#endif

//利用friend友元函数对操作符<<进行重载
#ifndef ostream1

#include <iostream>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream&, const Date&);

	int year;
	int month;
	int day;
public:
	Date() { year = 2013; month = 9; day = 30; }
};

ostream& operator<<(ostream& out, const Date& date)
{
	out << date.year << '-' << date.month << '-' << date.day;
	return out;
}

int main()
{
	Date date;
	cout << date << endl;
	system("pause");
}
#endif // !ostream1
