// 03 类模板.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template<class T>
class Person
{
public:
	Person(T id,T age)
	{
		this->mId = id;
		this->mAge = age;
	};
	void Show()
	{
		cout << this->mId << this->mAge << endl;
	}
	~Person()
	{

	};

public:
	T mId;
	T mAge;
};

void test01() {
	//类模板必须显示指定类型 <type>;
	Person<int> p(10, 100);
	p.Show();

}

int main()
{
	test01();
    return 0;
}

