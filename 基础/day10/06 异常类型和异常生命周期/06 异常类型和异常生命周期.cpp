// 06 异常类型和异常生命周期.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class MyException {
public:
	MyException(string&& str)
	{
		this->error = str;
	}
	void what()
	{
		cout << this->error << endl;
	}
public:
	string error;
};

void func01()
{
	throw 1; 
}

void func02()
{
	throw "exception";
}

void func03()
{
	throw MyException("我刚写的异常");
}

void test01()
{
	try
	{
		func01();
	}
	catch (int e)
	{
		cout << "异常捕获" << endl;
	}

#if 0
	try
	{
		func02();
	}
	catch (char* e)
	{
		cout << "异常捕获" << endl;
	}
#endif // 0

	try
	{
		func03();
	}
	catch (MyException e)
	{
		e.what();
	}

}

int main()
{
	test01();
    return 0;
}

