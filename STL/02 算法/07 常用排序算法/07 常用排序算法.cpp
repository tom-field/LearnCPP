#define _CRT_SECURE_NO_WARNINGS
#include "pch.h"
#include<iostream>
#include <algorithm>
#include <vector>
#include <functional>
#include <ctime>

using namespace std;

/*
merge算法 容器元素合并，并存储到另一容器中  这两个容器 必须也是有序的
@param beg1 容器1开始迭代器
@param end1 容器1结束迭代器
@param beg2 容器2开始迭代器
@param end2 容器2结束迭代器
@param dest  目标容器开始迭代器
*/
void test01()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 10);
	}

	vector<int>vTarget;
	vTarget.resize(v1.size() + v2.size());
	merge(v1.begin(), v1.end(), v2.begin(), v2.end(), vTarget.begin());

	for_each(vTarget.begin(), vTarget.end(), [](int v) { cout << v << " "; });
}

/*
sort算法 容器元素排序
注意:两个容器必须是有序的
@param beg 容器1开始迭代器
@param end 容器1结束迭代器
@param _callback 回调函数或者谓词(返回bool类型的函数对象)
*/
void test02()
{
	vector<int>v1;

	v1.push_back(10);
	v1.push_back(40);
	v1.push_back(20);
	v1.push_back(90);
	v1.push_back(50);


	sort(v1.begin(), v1.end());
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
	cout << endl;

	sort(v1.begin(), v1.end(), greater<int>());
	for_each(v1.begin(), v1.end(), [](int val) {cout << val << " "; });
	cout << endl;
}

//random_shuffle(iterator beg, iterator end) 洗牌
void test03()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	random_shuffle(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

//reverse(iterator beg, iterator end)
void test04()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	reverse(v.begin(), v.end());
	for_each(v.begin(), v.end(), [](int val) {cout << val << " "; });
}

void test05()
{
	
}

int main() {
	// random_shuffle用
	srand((unsigned int)time(NULL));

	//test01();

	//test02();

	//test03();

	test04();

	system("pause");
	return EXIT_SUCCESS;
}