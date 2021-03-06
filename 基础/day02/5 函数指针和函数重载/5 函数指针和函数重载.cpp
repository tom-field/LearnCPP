// 5 函数指针和函数重载.cpp: 定义控制台应用程序的入口点。
// TODO 指针学习

#include "stdafx.h"
#include <iostream>

using namespace std;

void func(int a, int b)
{
	cout << a << b << endl;
}

void func(int a, int b, int c)
{
	cout << a << b << c << endl;
}


void func(int a, int b, int c, int d)
{
	cout << a << b << c << d << endl;
}

//1 定义一个函数类型 TODO 学习typedef
typedef void(myfunctype)(int, int); //定义了一个函数类型， 返回值void 参数列表是 int，int   ,, void()(int,int)

									//2 定义一个函数指针类型 
typedef void(*myfunctype_pointer)(int, int); //定义了一个函数指针类型， 返回值void 参数列表是 int，int   ,, void(*)(int,int)


int main()
{
	// TODO
	//1 定义一个函数吗?
	myfunctype *p1 = NULL;
	p1 = func;
	//myfunctype *p1 = &func;
	p1(10, 10);

	//2 定义一个函数指针
	myfunctype_pointer p2 = NULL;
	p2 = func;
	p2(10, 20);

	//myfunctype p3 = func; //为什么会报错

	// 3 直接定义一个函数指针
	void(*p4)(int, int) = func;

	p4(10, 30);

	void(*p5)(int, int, int) = func; //在堆函数指针赋值的时候，函数指针会根据自己的类型 找到一个重载函数

	p5(10, 20, 30);
	//fp4(10, 20, 30, 40);
	//函数指针，调用的时候是不能够发生函数重载的。

    return 0;
}

