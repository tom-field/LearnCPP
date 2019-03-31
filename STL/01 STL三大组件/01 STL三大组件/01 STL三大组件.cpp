#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void test01() {
	int arr[5] = { 1,2,3,5,6 };
	//普通遍历
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << arr[i] << endl;
	}
	//指针遍历
	int *p = arr;
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << *p << endl;
		*(p++);
	}
}

void myPrint(int v) {
	cout << v << endl;
}

void test02() {
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		//加入数目
		v.push_back(i);
	}
	cout << "普通遍历" << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}

	vector<int>::iterator itBegin = v.begin();
	vector<int>::iterator itEnd = v.end();       //迭代器的最后一个位置的下一个位置
	cout << *itBegin << endl;
	//cout << *itEnd << endl;          //out of range vector iterator

	cout << "利用迭代器遍历" << endl;
	/*while (itBegin != itEnd)
	{
		cout << *itBegin << endl;
		itBegin++;
	}*/

	//第二种迭代 比较常用
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << endl;
	}

	//第三种迭代 利用算法
	for_each(v.begin(), v.end(), myPrint);

	cout << v.size() << endl;
	cout << v.capacity() << endl;
}

//操作自定义数据类型
class Person
{
public:
	Person();
	Person(string name, int age);
	~Person();

	string m_Name;
	int m_age;
private:
};

Person::Person(string name, int age)
{
	this->m_Name = name;
	this->m_age = age;
}

Person::~Person()
{
}
//存放自定义数据类型
void test03()
{
	vector<Person> v;
	Person p1("a", 10);
	Person p2("b", 10);
	Person p3("c", 10);
	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	cout << "遍历" << endl;
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "姓名:" << (*it).m_Name << "年龄:" << it->m_age << endl;
	}
}
//存放自定义数据类型指针
void test04()
{
	vector<Person *> v;
	Person p1("a", 10);
	Person p2("b", 10);
	Person p3("c", 10);
	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	cout << "遍历" << endl;
	for (vector<Person *>::iterator it = v.begin(); it != v.end(); it++)
	{
		//
		cout << "姓名::" << (*it)->m_Name << "年龄:" << (*it)->m_age << endl;
	}
}
//容器嵌套容器
void test05()
{
	vector<vector<int>> v;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	for (int i = 0; i < 5; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
		v3.push_back(i + 100);
	}
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);

	//遍历所有数据
	for (vector<vector<int>>::iterator it = v.begin(); it != v.end(); it++)
	{
		for (vector<int>::iterator secIt = (*it).begin(); secIt != (*it).end(); secIt++) {
			cout << (*secIt) << " ";
		}
		cout << endl;
	}
}

int main(void)
{
	//test01();
	//test02();
	//test03();
	//test04();
	test05();
	return 0;
}