#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class GreaterThen20
{
public:
	bool operator()(int val)
	{
		return val > 20;
	}
};

//一元谓词
void test01()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	//查找第一个大于20的数字

	//第三个参数 函数对象  匿名对象
	vector<int>::iterator pos = find_if(v.begin(), v.end(), GreaterThen20());
	if (pos != v.end())
	{
		cout << "找到大于20的数字为：" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

//二元谓词
class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};
void test02()
{
	vector<int>v;
	v.push_back(10);
	v.push_back(20);
	v.push_back(30);
	v.push_back(40);
	v.push_back(50);

	sort(v.begin(), v.end(), MyCompare());

	//匿名函数  lambda表达式  [](){};
	for_each(v.begin(), v.end(), [](int val) {
		cout << val << endl;
	});
}

void test03()
{
}

void test04()
{
}

void test05()
{
}

void test06()
{
}

void test07()
{
}

void test08()
{
}

int main(void)
{
	test01();
	test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	return 0;
}