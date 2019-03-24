#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//capacity 动态增长
void test01()
{
	vector<int> v;
	for (int i = 0; i < 100; i++)
	{
		v.push_back(i);
		cout << v.capacity() << endl;
	}
}

void vectorPrint(const vector<int> &v)
{
	for (vector<int>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

/*
3.2.4.1 vector构造函数
vector<T> v; //采用模板实现类实现，默认构造函数
vector(v.begin(), v.end());//将v[begin(), end())区间中的元素拷贝给本身。
vector(n, elem);//构造函数将n个elem拷贝给本身。
vector(const vector &vec);//拷贝构造函数。
*/
void test02()
{
	vector<int> v0;

	int arr[] = { 2,3,4,2,9 };
	vector<int> v1(arr, arr + sizeof(arr) / sizeof(int));
	vector<int> v2(v1.begin(), v1.end());
	vector<int> v3(10, 100);
	vector<int> v4(v3);
	
	vectorPrint(v0);
	vectorPrint(v1);
	vectorPrint(v2);
	vectorPrint(v3);
	vectorPrint(v4);
}

/*
3.2.4.2 vector常用赋值操作
assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
assign(n, elem);//将n个elem拷贝赋值给本身。
vector& operator=(const vector  &vec);//重载等号操作符
swap(vec);// 将vec与本身的元素互换。
*/
void test03()
{
	vector<int> v3(10, 100);
	vector<int> v4;
	v4.assign(v3.begin(), v3.end());

	vector<int> v5;
	v5.assign(10, 99);

	vector<int> v6 = v5;

	vector<int> v7;
	v7.push_back(1);
	v7.push_back(2);
	v7.push_back(3);
	vector<int> v8;
	v8.push_back(8);
	v8.push_back(9);
	v8.push_back(10);
	v8.push_back(11);
	cout << "交换前的v7" << endl;
	vectorPrint(v7);
	cout << "交换前的v8" << endl;
	vectorPrint(v8);
	v7.swap(v8);
	cout << "交换后的v7" << endl;
	vectorPrint(v7);
	cout << "交换后的v8" << endl;
	vectorPrint(v8);

	//巧用swap
	vector<int> v9;
	for (int i = 0; i < 100000; i++)
	{
		v9.push_back(i);
	}
	cout << "v9的容量:" << v9.capacity() << endl;
	cout << "v的大小:" << v9.size() << endl;
	
	v9.resize(3);

	cout << "v9的容量:" << v9.capacity() << endl;
	cout << "v的大小:" << v9.size() << endl;

	vector<int>(v9).swap(v9);

	cout << "v9的容量:" << v9.capacity() << endl;
	cout << "v的大小:" << v9.size() << endl;


	vectorPrint(v4);
	vectorPrint(v5);
	vectorPrint(v6);
}

/*
3.2.4.3 vector大小操作
size();//返回容器中元素的个数
empty();//判断容器是否为空
resize(int num);//重新指定容器的长度为num，若容器变长，则以默认值填充新位置。如果容器变短，则末尾超出容器长度的元素被删除。
resize(int num, elem);//重新指定容器的长度为num，若容器变长，则以elem值填充新位置。如果容器变短，则末尾超出容器长>度的元素被删除。
capacity();//容器的容量
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
*/
void test04()
{

}

/*
3.2.4.4 vector数据存取操作
at(int idx); //返回索引idx所指的数据，如果idx越界，抛出out_of_range异常。
operator[];//返回索引idx所指的数据，越界时，运行直接报错
front();//返回容器中第一个数据元素
back();//返回容器中最后一个数据元素
*/
void test05()
{
	
}

/*
3.2.4.5 vector插入和删除操作
insert(const_iterator pos, int count,ele);//迭代器指向位置pos插入count个元素ele.
push_back(ele); //尾部插入元素ele
pop_back();//删除最后一个元素
erase(const_iterator start, const_iterator end);//删除迭代器从start到end之间的元素
erase(const_iterator pos);//删除迭代器指向的元素
clear();//删除容器中所有元素
*/
void test06()
{
	
}

void test07()
{
	//逆序遍历
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	//for (vector<int>::iterator it = v.rbegin(); it != v.rend(); it--)
	//报错 reverse_iterator无法转换为 vector_iterator
	for (vector<int>::reverse_iterator it = v.rbegin(); it != v.rend(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
	
	//vector迭代器是随机访问的迭代器 支持跳跃式访问
	vector<int>::iterator it = v.begin();
	it += 9;
	//如果上述写法不报错,这个迭代器是支持随机访问迭代器
	cout << *it << endl;
}

/*
判断开辟100000个数据开辟了多少次空间
*/
void test08()
{
	int *p = NULL;
	int num = 0;
	vector<int> v;
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
		if (p != &v[0]) {
			p = &v[0];
			num++;
		}
	}
	cout << num << endl;
}

int main(void)
{
	//test01();
	//test02();
	//test03();

	test07();
	test08();
	return 0;
}
