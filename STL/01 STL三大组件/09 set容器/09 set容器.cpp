#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

void printSet(set<int> s)
{
	for (set<int>::iterator i = s.begin(); i != s.end(); i++)
	{
		cout << *i << " ";
	}
	cout << endl;
}

//3.7.2.1 set构造函数
//set<T> st;//set默认构造函数：
//mulitset<T> mst; //multiset默认构造函数:
//set(const set &st);//拷贝构造函数
void test01()
{
	set<int> s;
	set<int> s1;
	s1 = s;
	multiset<int> ms;
}

//3.7.2.2 set赋值操作
//set& operator=(const set &st);//重载等号操作符
//swap(st);//交换两个集合容器
void test02()
{
	set<int> s1;
	s1.insert(5);
	s1.insert(3);
	s1.insert(1);
	cout << "s1:" << endl;
	printSet(s1);
	set<int> s2;
	s2.insert(8);
	s2.insert(9);
	s2.insert(7);
	s2.insert(6);
	cout << "s2:" << endl;
	printSet(s2);
	cout << "s1 s2 交换:" << endl;
	s1.swap(s2);
	printSet(s1);
	printSet(s2);
	cout << "s2 赋值给 s1: " << endl;
	s1 = s2;
	printSet(s1);
	printSet(s2);
}

//3.7.2.3 set大小操作
//size();//返回容器中元素的数目
//empty();//判断容器是否为空
void test03()
{
	set<int> s1;
	s1.insert(5);
	s1.insert(3);
	s1.insert(1);

	cout << sizeof(s1) << endl;
	cout << s1.size() << endl;
	cout << s1.empty() << endl;
}

//3.7.2.4 set插入和删除操作
//insert(elem);//在容器中插入元素。
//clear();//清除所有元素
//erase(pos);//删除pos迭代器所指的元素，返回下一个元素的迭代器。
//erase(beg, end);//删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
//erase(elem);//删除容器中值为elem的元素。
void test04()
{
}

//3.7.2.5 set查找操作
//find(key);//查找键key是否存在,若存在，返回该键的元素的迭代器；若不存在，返回set.end();
//count(key);//查找键key的元素个数
//lower_bound(keyElem);//返回第一个key>=keyElem元素的迭代器。
//upper_bound(keyElem);//返回第一个key>keyElem元素的迭代器。
//equal_range(keyElem);//返回容器中key与keyElem相等的上下限的两个迭代器。
void test05()
{
	set<int> s;
	s.insert(3);
	s.insert(1);
	s.insert(5);

	set<int>::iterator pos = s.find(3);
	if (pos != s.end())
	{
		cout << "找到" << *pos << endl;
	}
	else {
		cout << "未找到" << endl;
	}

	int num = s.count(5);
	cout << "5的个数:" << num << endl;

	set<int>::iterator lower_bound = s.lower_bound(3);
	cout << "s.lower_bound(3):" << *lower_bound << endl;

	set<int>::iterator upper_bound = s.upper_bound(3);
	//这种写法不安全 有可能找不到
	cout << "s.upper_bound(3):" << *upper_bound << endl;

	set<int>::iterator upb = s.upper_bound(10);
	//这种安全 找不到不执行
	if (upb != s.end())
	{
		cout << "s.upper_bound(10):" << *upb << endl;
	}

	//上下限的两个迭代器
	pair<set<int>::iterator, set<int>::iterator> pair = s.equal_range(3);
	//获取第一个值
	if (pair.first != s.end())
	{
		cout << "找到 equal_range 的lower_bound:" << *pair.first << endl;
	}
	if (pair.second != s.end())
	{
		cout << "找到 equal_range 的upper_bound:" << *pair.second << endl;
	}
}

//set容器不允许插入重复的元素
void test06()
{
	set<int> s;
	pair<set<int>::iterator, bool> ret1 = s.insert(10);
	pair<set<int>::iterator, bool> ret2 = s.insert(10);
	if (ret1.second) {
		cout << "元素1插入成功" << endl;
	}
	else {
		cout << "元素1插入失败" << endl;
	}
	if (ret2.second)
	{
		cout << "元素2插入成功" << endl;
	}
	else {
		cout << "元素2插入失败" << endl;
	}
}

//指定set排序规则
//仿函数
class MyCompare
{
public:
	bool operator()(int v1, int v2)
	{
		return v1 > v2;
	}
};

//set容器排序 从小到大 从大到小
void test07()
{
	set<int, MyCompare> s;
	s.insert(5);
	s.insert(1);
	s.insert(9);
	s.insert(3);
	s.insert(7);
	//printSet(s);
	for (set<int, MyCompare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
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

class MyPersonCompare
{
public:
	//最好带上引用的话要加const修饰
	bool operator()(const Person &p1, const Person &p2)
	{
		return p1.age > p2.age;
	}
};

//插入自定义数据类型
void test08()
{
	Person p1("小明", 18, 189);
	Person p2("小✿", 16, 165);
	Person p3("小张", 18, 170);
	Person p4("小芳", 20, 170);

	set<Person, MyPersonCompare> s;
	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);

	// 仿函数不能写在自定义类型中
	/*for (set<Person,Person>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "name:" << (*it).name << "age:" << (*it).age << "height" << (*it).height << endl;
	}*/
	for (set<Person, MyPersonCompare>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "name:" << (*it).name << "age:" << (*it).age << "height" << (*it).height << endl;
	}
}

int main(void)
{
	//test01();
	//test02();
	test03();
	test04();
	test05();
	test06();
	test07();
	test08();
	return 0;
}