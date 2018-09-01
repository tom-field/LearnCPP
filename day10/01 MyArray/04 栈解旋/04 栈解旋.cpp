// 04 栈解旋.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Person
{
public:
	Person()
	{
	
	};
	~Person() 
	{
		cout << "析构函数" << endl;
	};

private:

};

//异常基本语法
int divide(int x, int y)
{
	//当抛出异常时p1和p2会被析构
	Person p1, p2;
	if (y == 0)
	{
		throw y;
	}
	return x / y;
}

void test01()
{
	try
	{
		divide(10, 0);
	}
	catch (int e)
	{
		cout << "异常:" << e << endl;
	}
}

int main()
{
	test01();
    return 0;
}

