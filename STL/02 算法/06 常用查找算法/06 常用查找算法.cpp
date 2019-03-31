#include "pch.h"
#include<iostream>
#include <algorithm>
using namespace std;
#include <vector>
#include <string>
#include <functional>
/*
find算法 查找元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return 返回查找元素的位置
*/
void test01()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}
	vector<int>::iterator pos = find(v.begin(), v.end(), 5);
	if (pos!=v.end())
	{
		cout << "找到了数据：" << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	
}

class Person
{
public:
	Person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	bool operator==( const Person&p)
	{
		if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
		{
			return true;
		}
		return false;
	}
	
	string m_Name;
	int m_Age;
};
//利用find查找自定义数据类型
void test02()
{
	vector<Person>v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(p1);
	v.push_back(p2);
	v.push_back(p3);
	v.push_back(p4);

	vector<Person>::iterator pos = find(v.begin(), v.end(), p2);
	
	if (pos != v.end())
	{
		cout << "找到了数据姓名：" << (*pos).m_Name << " 年龄：" << pos->m_Age << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

//利用find查找 指针
void test021() {
	class Person
	{
	public:
		Person(string name, int age)
		{
			this->m_Name = name;
			this->m_Age = age;
		}

		bool operator==(const Person&p)
		{
			if (this->m_Name == p.m_Name && this->m_Age == p.m_Age)
			{
				return true;
			}
			return false;
		}

		string m_Name;
		int m_Age;
	};

	vector<Person*>v;

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	Person p5 = Person("bbb", 20);
	
	//vector<Person*>::iterator pos = find(v.begin(), v.end(), &p2);
	vector<Person*>::iterator pos = find(v.begin(), v.end(),&p5);

	if (pos != v.end())
	{
		cout << "找到了数据姓名：" << (*pos)->m_Name << " 年龄：" << (*pos)->m_Age << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}

void test03()
{
	class MyCompare :public binary_function<Person*, Person*, bool>
	{
	public:
		bool operator()(Person * p1, Person * p2) const
		{
			if (p1->m_Name == p2->m_Name && p1->m_Age == p2->m_Age)
			{
				return true;
			}
			return false;
		}

	};

	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);

	vector<Person *>v;

	v.push_back(&p1);
	v.push_back(&p2);
	v.push_back(&p3);
	v.push_back(&p4);

	Person * p = new Person("bbb", 20);
	vector<Person*>::iterator pos = find_if(v.begin(), v.end(),  bind2nd( MyCompare(), p));

	if (pos != v.end())
	{
		cout << "找到了数据姓名：" << (*pos)->m_Name << " 年龄：" << (*pos)->m_Age << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
}


/*
adjacent_find算法 查找相邻重复元素
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  _callback 回调函数或者谓词(返回bool类型的函数对象)
@return 返回相邻元素的第一个位置的迭代器
*/
void test04()
{
	vector<int>v;
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(5);
	v.push_back(6);
	v.push_back(2);

	vector<int>::iterator pos = adjacent_find(v.begin(), v.end());

	if (pos!= v.end())
	{
		cout << "找到了相邻重复元素为： " << *pos << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}
	
}

/*
binary_search算法 二分查找法
注意: 在无序序列中不可用
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param value 查找的元素
@return bool 查找返回true 否则false
*/
void test05()
{
	vector<int>v;
	for (int i = 0; i < 10;i++)
	{
		v.push_back(i);
	}

	bool ret =  binary_search(v.begin(), v.end(), 4);
	if (ret)
	{
		cout << "找到了4" << endl;
	}
	else
	{
		cout << "未找到" << endl;
	}

}

/*
/*
count算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  value回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数
*/

/*
count_if算法 统计元素出现次数
@param beg 容器开始迭代器
@param end 容器结束迭代器
@param  callback 回调函数或者谓词(返回bool类型的函数对象)
@return int返回元素个数

*/
class GreaterThenFour
{

public:
	bool operator()(int v)
	{
		return v >= 4;
	}

};
void test06()
{
	
	vector<int>v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	v.push_back(4);
	v.push_back(4);
	v.push_back(4);
	v.push_back(4);

	int num = count(v.begin(), v.end(), 4);
	cout << "4的个数为" << num << endl;

	num = count_if(v.begin(), v.end(), GreaterThenFour());
	cout << "大于等于 4的个数为" << num << endl;

}


int main(){

	//test01();

	//test02();

	//test021();

	test03();

	//test04();

	//test05();

	//test06();

	system("pause");
	return EXIT_SUCCESS;
}