#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

void test01()
{
	//template<class T> T negate<T>//取反仿函数
	negate<int> n;

	cout << n(10) << endl;

	//加法  template<class T> T plus<T>//加法仿函数

	plus<int> p;

	cout << p(1, 1) << endl;
}

//template<class T> bool greater<T>//大于
void test02()
{
	vector<int>v;

	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	sort(v.begin(), v.end(), greater<int>());

	for_each(v.begin(), v.end(), [](int val) { cout << val << " "; });
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