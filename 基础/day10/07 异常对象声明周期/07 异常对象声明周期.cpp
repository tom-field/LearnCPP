// 07 异常对象声明周期.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class MyException {
public:
	MyException()
	{
		cout << "构造函数" << endl;
	}
	MyException(const MyException& myexception)
	{
		cout << "拷贝构造" << endl;
	}
	~MyException()
	{
		cout << "析构" << endl;
	}
	
public:
	
};

void test01() {
	try
	{
		throw MyException();
	}
	catch (MyException e)
	{
		//分别用普通类型元素 引用 指针接收
		cout << "异常捕获" << endl;
		//普通元素 异常处理完成析构
		//引用的话 不用调用拷贝构造 异常处理完就析构

		//指针接收 对抛出的匿名对象取地址后抛出 构造->析构->执行捕获逻辑 如果在捕获中调用对象属性方法的话就调用不到了
		//如果捕获里要对异常对象进行操作 可以抛出 new Exception(); 在捕获的最后 delete掉
	}
}

int main()
{
	test01();
    return 0;
}

