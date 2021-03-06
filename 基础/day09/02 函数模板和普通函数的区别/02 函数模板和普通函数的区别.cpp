// 02 函数模板和普通函数的区别.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//普通函数可以进行自动类型转化
//函数模板必须严格类型匹配

template<class T>
T MyAdd(T a, T b)
{
	return a + b;
}

int MyAdd(int a, char b)
{
	return a + b;
}

void test01()
{
	int a = 10;
	int b = 20;
	char c1 = 'a';
	char c2 = 'b';

	//调用上面的函数
	cout << MyAdd<int>(a, b) << endl;
	//调用下面的函数
	cout << MyAdd(a, c1) << endl;
	//调用下面的函数
	cout << MyAdd(c1, c2) << endl;
	cout << a << endl;
}

//函数模板可以向普通函数那样被重载
template<class T>
void Print(T a)
{

}

template<clas T>
void Print(T a, T b)
{

}

int main()
{
	test01();
    return 0;
}

