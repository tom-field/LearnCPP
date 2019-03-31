#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class MyPrint
{
public:
	void operator()(int num)
	{
		cout << "num " << num << endl;
		count++;
	}
	int count = 0;
};

void MyPrint2(int num)
{
	cout << "num " << num << endl;
}

void test01()
{
	MyPrint()(1000);
	MyPrint2(100);
}

//函数对象超出普通函数概念，内部可以保存状态
void test02()
{
	MyPrint myPrint;
	myPrint(111);
	myPrint(111);
	myPrint(111);
	myPrint(111);

	cout << "myPrint使用次数：" << myPrint.count << endl;
}

//函数对象作为参数
void doPrint(MyPrint print, int num)
{
	print(num);
}

void test03()
{
	doPrint(MyPrint(), 20);
}

void test04()
{
}

void test05()
{
}

void test06()
{
}

void test07()
{
}

void test08()
{
}

int main(void)
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	return 0;
}