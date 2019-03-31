#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>

using namespace std;

void printMap(map<int, int> m)
{
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key:" << it->first << " value:" << it->second << endl;
	}
}

//3.8.2.1 map构造函数
//map<T1, T2> mapTT;//map默认构造函数:
//map(const map &mp);//拷贝构造函数
void test01()
{
}

//3.8.2.2 map赋值操作
//map& operator=(const map &mp);//重载等号操作符
//swap(mp);//交换两个集合容器
void test02()
{
}

//3.8.2.3 map大小操作
//size();//返回容器中元素的数目
//empty();//判断容器是否为空
void test03()
{
}

//3.8.2.4 map插入数据元素操作
//map.insert(...); //往容器插入元素，返回pair<iterator,bool>
//map<int, string> mapStu;
//// 第一种 通过pair的方式插入对象
//mapStu.insert(pair<int, string>(3, "小张"));
//// 第二种 通过pair的方式插入对象
//mapStu.inset(make_pair(-1, "校长"));
//// 第三种 通过value_type的方式插入对象
//mapStu.insert(map<int, string>::value_type(1, "小李"));
//// 第四种 通过数组的方式插入值
//mapStu[3] = "小刘";
//mapStu[5] = "小王";
// map实例化
void test04()
{
	map<int, int> m;
	//插入方式 4中
	//第一种
	m.insert(pair<int, int>(1, 10));
	//第二种 推荐
	m.insert(make_pair(2, 20));
	//第三种 不推荐
	m.insert(map<int, int>::value_type(3, 30));
	//第四种 不推荐 如果确定存在可以用它获取value
	m[4] = 40;
	m[5];
	cout << m[4] << endl;

	printMap(m);
}

//3.8.2.5 map删除操作
//clear();//删除所有元素
//erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
//erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
//erase(keyElem);//删除容器中key为keyElem的对组。
void test05()
{
	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(6, 60));
	printMap(m);
	cout << "删除第二个到到倒数第二个" << endl;
	m.erase(++m.begin(), --m.end());
	printMap(m);
	cout << "删除key为1的元素" << endl;
	m.erase(1);
	printMap(m);
	cout << "清空元素" << endl;
	m.clear();
	printMap(m);
}

//3.8.2.6 map查找操作
//find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；/若不存在，返回map.end();
//count(keyElem);//返回容器中key为keyElem的对组个数。对map来说，要么是0，要么是1。对multimap来说，值可能大于1。
//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
void test06()
{
	map<int, int> m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));
	m.insert(make_pair(6, 60));

	map<int, int>::iterator pos = m.find(1);
	if (pos != m.end())
	{
		cout << "找到元素" << (*pos).first << " " << (*pos).second << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

	cout << "key为2的对组个数为" << m.count(2) << endl;
	cout << "key为7的对组个数为" << m.count(7) << endl;

	int search = 3;
	map<int, int>::iterator it_lower_bound = m.lower_bound(3);
	if (it_lower_bound != m.end()) {
		cout << "lower_bound(" << search << ")" << (*it_lower_bound).first << " " << (*it_lower_bound).second << endl;
	}
	else {
		cout << "未找到lower_bound(" << search << ")" << endl;
	}

	search = 10;
	it_lower_bound = m.lower_bound(search);
	if (it_lower_bound != m.end()) {
		cout << "lower_bound(" << search << ") " << (*it_lower_bound).first << " " << (*it_lower_bound).second << endl;
	}
	else {
		cout << "未找到lower_bound(" << search << ")" << endl;
	}

	search = 3;
	map<int, int>::iterator it_upper_bound = m.upper_bound(3);
	if (it_upper_bound != m.end()) {
		cout << "upper_bound(" << search << ") " << (*it_upper_bound).first << " " << (*it_upper_bound).second << endl;
	}
	else {
		cout << "未找到upper_bound(" << search << ") " << endl;
	}

	search = 10;
	it_upper_bound = m.upper_bound(search);
	if (it_upper_bound != m.end()) {
		cout << "upper_bound(" << search << ") " << (*it_upper_bound).first << " " << (*it_upper_bound).second << endl;
	}
	else
	{
		cout << "未找到upper_bound(" << search << ") " << endl;
	}

	search = 3;
	pair<map<int, int>::iterator, map<int, int>::iterator> pair_equal_range = m.equal_range(search);
	if (pair_equal_range.first != m.end())
	{
		cout << "upper_bound(" << search << ") key: " << (*((pair_equal_range).first)).first << " value:" << (*((pair_equal_range).first)).second << endl;
	}
	else {
		cout << "未找到lower_bound(" << search << ")" << endl;
	}
	if (pair_equal_range.second != m.end())
	{
		cout << "找到upper_bound(" << search << ") key: " << (*((pair_equal_range).second)).first << " value: " << (*((pair_equal_range).second)).second << endl;
	}
	else {
		cout << "未找到upper_bound(" << search << ")";
	}
}

//指定set排序规则
//仿函数 struct或者class
struct myCompare
{
	bool operator()(const int& p1, const int& p2)
	{
		return p1 > p2;
	}
};

// 排序
void test07()
{
	map<int, int, myCompare> m;
	m.insert(make_pair(4, 40));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(1, 10));
	m.insert(make_pair(3, 30));
	for (map<int, int, myCompare>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << (*it).first << " " << (*it).second << endl;
	}
}

class Person
{
public:
	Person(string name, int age, int height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	};
	bool operator()(Person p1, Person p2)
	{
		return p1.age > p2.age;
	}
	string name;
	int age;
	int height;
};
// 插入自定义数据并排序
void test08()
{
}

int main(void)
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	test07();
	//test08();
	return 0;
}