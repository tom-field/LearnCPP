#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

//3.5.3.1 queue构造函数
//queue<T> queT;//queue采用模板类实现，queue对象的默认构造形式：
//queue(const queue &que);//拷贝构造函数
void test01()
{

}

//3.5.3.2 queue存取、插入和删除操作
//push(elem);//往队尾添加元素
//pop();//从队头移除第一个元素
//back();//返回最后一个元素
//front();//返回第一个元素
void test02()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.pop();
	cout << q.front() << endl;
	cout << q.back() << endl;
}

//3.5.3.3 queue赋值操作
//queue& operator=(const queue &que);//重载等号操作符
void test03()
{

}

//3.5.3.4 queue大小操作
//empty();//判断队列是否为空
//size();//返回队列的大小
void test04()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	while (!q.empty())
	{
		cout << q.size() << endl;
		q.pop();
	}
}

int main(void)
{
	//test01();
	//test02();
	//test03();
	test04();
	return 0;
}