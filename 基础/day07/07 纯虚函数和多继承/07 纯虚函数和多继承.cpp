// 07 纯虚函数和多继承.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class Interface1
{
public:
	virtual void func(int a, int b) = 0;
	virtual void func2(int a) = 0;
private:

};

class Interface2
{
public:
	virtual void func3(int a, int b) = 0;
private:

};

class Child : public Interface1,public Interface2
{
public:
	virtual void func(int a, int b)
	{
		cout << "a = " << a << "b = " << b << endl;
	}
	virtual void func2(int a)
	{
		cout << "a = " << a << endl;
	}
	virtual void func3(int a, int b)
	{
		cout << "a = " << a << "b = " << b << endl;
	}
private:

};

void test(Interface2 *if2)
{

}

int main()
{
	Interface1 *if1 = new Child;
	Interface2 *if2 = new Child;

	if1->func(10,20);
	if1->func2(10);
	if2->func3(10, 20);

    return 0;
}
