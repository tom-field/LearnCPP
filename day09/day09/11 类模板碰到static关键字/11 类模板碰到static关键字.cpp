// 11 类模板碰到static关键字.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<class T>
class Person{
public:
	static int a;
};

//类外初始化
template<class T> int Person<T>::a = 0;

int main()
{
	Person<int> p1, p2, p3;
	Person<char> pp1, pp2,pp3;

	//Person<int> Person<int> 模板生成的具体类 他们的静态成员变量不是同一块内存区域

	p1.a = 10;
	pp1.a = 100;

	cout << p1.a << p2.a << p3.a << endl;
	cout << pp1.a << pp2.a << pp3.a << endl;
    return 0;
}

