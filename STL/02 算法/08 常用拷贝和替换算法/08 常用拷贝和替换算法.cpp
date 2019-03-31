﻿#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <vector>
#include <algorithm>
#include <iterator>

using namespace std;

/*
copy算法 将容器内指定范围的元素拷贝到另一容器中
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param dest 目标起始迭代器
*/

void test01()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int>vTarget;
	vTarget.resize(v.size());

	copy(v.begin(), v.end(), vTarget.begin());

	//for_each(vTarget.begin(), vTarget.end(), [](int val){ cout << val << " "; });

	copy(vTarget.begin(), vTarget.end(), ostream_iterator<int>(cout, " "));
}

/*
replace算法 将容器内指定范围的旧元素修改为新元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param oldvalue 旧元素
@param oldvalue 新元素

replace_if算法 将容器内指定范围满足条件的元素替换为新元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param callback函数回调或者谓词(返回Bool类型的函数对象)
@param oldvalue 新元素
*/
class MyCompare
{
public:
	bool operator()(int v)
	{
		return v > 3;
	}
};
void test02()
{
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	//需求 把容器中的3  替换成300
	replace(v.begin(), v.end(), 3, 300);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	//需求  把容器中所有大于3的数字 都替换成 30000

	replace_if(v.begin(), v.end(), MyCompare(), 30000);

	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
}

/*
swap算法 互换两个容器的元素
@param c1容器1
@param c2容器2
*/

void test03()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int>v2;
	v2.push_back(10);
	v2.push_back(30);
	v2.push_back(20);
	v2.push_back(40);

	cout << "交换前数据：" << endl;

	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

	cout << "交换后的数据:" << endl;

	swap(v1, v2);

	copy(v1.begin(), v1.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
	copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
	cout << endl;

}


int main() {

	//test01();

	//test02();

	test03();

	return EXIT_SUCCESS;
}