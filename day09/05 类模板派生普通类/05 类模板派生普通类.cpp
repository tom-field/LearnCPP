// 05 类模板派生普通类.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<class T>
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

public:
	T mAge;
};

//class SubPerson : public Person   为什么 这两种不行
//class SubPerson : public Person<T> 类去定义对象 需要分配内存不明确类型 不知道如何分配

class SubPerson : public Person<int>
{

};

int main()
{
    return 0;
}

