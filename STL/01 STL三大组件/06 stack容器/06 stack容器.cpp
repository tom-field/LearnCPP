#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;

//stack<T> stkT;//stack采用模板类实现， stack对象的默认构造形式：
//stack(const stack &stk);//拷贝构造函数
void test01()
{
}

//3.4.3.2 stack赋值操作
//stack& operator=(const stack &stk);//重载等号操作符
void test02()
{
}

//3.4.3.3 stack数据存取操作
//push(elem);//向栈顶添加元素
//pop();//从栈顶移除第一个元素
//top();//返回栈顶元素
void test03()
{
}

//3.4.3.4 stack大小操作
//empty();//判断堆栈是否为空
//size();//返回堆栈的大小
//empty();// 为空返回1 不为空返回0
void test04()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);
	while (s.size() != 0)
	{
		cout << s.top() << endl;
		s.pop();
	}
	cout << s.empty() << endl;
}

int main(void)
{
	test01();
	test02();
	test03();
	test04();
	return 0;
}