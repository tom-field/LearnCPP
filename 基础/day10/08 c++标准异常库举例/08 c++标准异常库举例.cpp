// 08 c++标准异常库举例.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <stdexcpt.h>

using namespace std;

class Person
{
public:
	Person()
	{
		this->mAge = 0;
	};
	~Person()
	{
	};
	void setAge(int age)
	{
		if (age < 0 || age>100)
		{
			throw out_of_range("年龄应该在0-100之间!");
		}
		this->mAge = age;
	}

private:
	int mAge;
};

int divide(int x, int y)
{
	return 0;
}

void test01() {
	try
	{
		Person p;
		p.setAge(1000);
	}
	//catch (out_of_range e) 
	catch (exception e)  //通用捕获
	{
		cout << e.what() << endl;
	}
}

//自己实现一个outofrange异常类
class MyOutOfRange:public exception
{
public:
	MyOutOfRange(const char* error)
	{
		this->pError = new char[strlen(error) + 1];
		strcpy(this->pError, error);
	};
	~MyOutOfRange()
	{
		if (pError != NULL) {
			delete[] this->pError;
		}
		this->pError = NULL;
	};
	virtual const char* what() const {
		return pError;
	}


private:
	char* pError;
};
void func02()
{
	throw MyOutOfRange("我自己定义的out_of_range");
}
void test02()
{
	try
	{
		func02();
	}
	//为什么写exception e ; e.what() 拿不到自己定义的数据 原因是没有写拷贝构造
	catch (exception& e) 
	{
		cout << e.what() << endl;
	}
}

int main()
{
	//test01();
	test02();
    return 0;
}

