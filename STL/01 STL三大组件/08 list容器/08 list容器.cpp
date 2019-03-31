#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <list>

using namespace std;

/*
	证明list是一个循环的双向链表
*/
void test01()
{
	// TODO 报错 C2227
	/*list<int> myList;
	for (int i = 0; i < 10; i++)
	{
		myList.push_back(i);
	}

	list<int>::_Nodeptr node = myList._Myhead->_Next;

	for (int i = 0; i < myList._Mysize * 2; i++)
	{
		cout << "Node:" << node->_Myval << endl;
		node = node->_Next;
		if (node == myList._Myhead)
		{
			node = node->_Next;
		}
	}*/
}

void printList(list<int> &L)
{
	cout << "正序: ";
	for (list<int>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	cout << "逆序: ";
	for (list<int>::reverse_iterator it = L.rbegin(); it != L.rend(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
	// list迭代器不支持随机访问
	/*list<int>::iterator it = L.begin() + 3;
	cout << it << endl;*/
}

//3.6.4.1 list构造函数
//list<T> lstT;//list采用采用模板类实现,对象的默认构造形式：
//list(beg, end);//构造函数将[beg, end)区间中的元素拷贝给本身。
//list(n, elem);//构造函数将n个elem拷贝给本身。
//list(const list &lst);//拷贝构造函数。
void test02()
{
	list<int> L1;
	list<int> L2(L1.begin(), L1.end());
	list<int> L3(10, 1);
	list<int> L4(L3);
	L4.push_back(10);
	printList(L4);
}

//3.6.4.2 list数据元素插入和删除操作
//push_back(elem);//在容器尾部加入一个元素
//pop_back();//删除容器中最后一个元素
//push_front(elem);//在容器开头插入一个元素
//pop_front();//从容器开头移除第一个元素
//insert(pos, elem);//在pos位置插elem元素的拷贝，返回新数据的位置。
//insert(pos, n, elem);//在pos位置插入n个elem数据，无返回值。
//insert(pos, beg, end);//在pos位置插入[beg,end)区间的数据，无返回值。
//clear();//移除容器的所有数据
//erase(beg, end);//删除[beg,end)区间的数据，返回下一个数据的位置。
//erase(pos);//删除pos位置的数据，返回下一个数据的位置。
//remove(elem);//删除容器中所有与elem值匹配的元素。
void test03()
{
	list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_front(30);
	L.push_front(40);
	L.insert(++L.begin(), 50);
	cout << "第二个位置插入1个50" << endl;
	printList(L);
	L.insert(++L.begin(), 3, 60);
	cout << "第二个位置插入3个60" << endl;
	printList(L);
	L.insert(L.begin(), L.begin(), L.end());
	cout << "拷贝L的数据,从头插到尾" << endl;
	printList(L);
	L.remove(10);
	cout << "删除所有的10" << endl;
	printList(L);
	L.erase(++L.begin());
	cout << "删除第二个元素" << endl;
	printList(L);
	L.erase(++L.begin(), --L.end());
	cout << "只保留头尾元素" << endl;
	printList(L);
	L.clear();
	cout << "清空List" << endl;
	printList(L);
}

//3.6.4.3 list大小操作
//size();//返回容器中元素的个数
//empty();//判断容器是否为空
//resize(num);//重新指定容器的长度为num，
//若容器变长，则以默认值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除。
//resize(num, elem);//重新指定容器的长度为num，
//若容器变长，则以elem值填充新位置。
//如果容器变短，则末尾超出容器长度的元素被删除。
void test04()
{
	list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_front(30);
	L.push_front(40);
	cout << L.size() << endl;
	cout << L.empty() << endl;
	L.resize(10);
	cout << "分配10个空间" << endl;
	printList(L);
	cout << "分配20个空间,填充100" << endl;
	L.resize(20, 100);
	printList(L);
}

//3.6.4.4 list赋值操作
//assign(beg, end);//将[beg, end)区间中的数据拷贝赋值给本身。
//assign(n, elem);//将n个elem拷贝赋值给本身。
//list& operator=(const list &lst);//重载等号操作符
//swap(lst);//将lst与本身的元素互换。
void test05()
{
	list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_front(30);
	L.push_front(40);
	cout << "list L" << endl;
	printList(L);
	list<int> L2;
	L2.push_back(50);
	L2.push_back(60);
	L2.push_front(70);
	cout << "list L2" << endl;
	printList(L2);
	L.assign(L2.begin(), L2.end());
	cout << "将L2的开始和结束区间元素拷贝给L" << endl;
	printList(L);
	L.assign(5, 6);
	cout << "将5个6拷贝给L" << endl;
	printList(L);
	list<int> L3;
	L3.push_back(10);
	L3.push_back(20);
	L3.push_front(30);
	L3.push_front(40);
	cout << "L3" << endl;
	printList(L3);
	list<int> L4;
	L4.push_back(50);
	L4.push_back(60);
	L4.push_back(70);
	cout << "L4" << endl;
	printList(L4);
	L3.swap(L4);
	cout << "L3与L4进行交换" << endl;
	cout << "L3:";
	printList(L3);
	cout << "L4:";
	printList(L4);
}

//3.6.4.5 list数据的存取
//front();//返回第一个元素。
//back();//返回最后一个元素。
//3.6.4.6 list反转排序
//reverse();//反转链表，比如lst包含1,3,5元素，运行此方法后，lst就包含5,3,1元素。
//sort(); //list排序
bool myCompare(int v1, int v2)
{
	return v1 > v2;
}
void test06()
{
	list<int> L;
	L.push_back(10);
	L.push_back(20);
	L.push_front(30);
	L.push_front(40);
	cout << L.front() << endl;
	cout << L.back() << endl;
	L.reverse();
	//TODO 为何 sort(L.begin(),L.end())报错
	// 所有不支持随机访问的迭代器 不可以使用系统提供的算法
	L.sort();
	cout << "默认从小到大排序" << endl;
	printList(L);
	L.sort(myCompare);
	cout << "自定义从大到小排序" << endl;
	printList(L);
}

//自定义数据类型排序
class Person
{
public:
	Person(string name, int age, int height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	};
	//重点:重载 == 让remove可以删除自定义的Person类型 注意必须要加const 不然任然报错
	//因为remove内部方法传值的时候带const修饰 所以重载时候要求也必须加const修饰
	bool operator==(const Person &p)
	{
		if (this->name == p.name && this->age == p.age && this->height == p.height)
		{
			return true;
		}
		return false;
	};
	string name;
	int age;
	int height;
};

void printPerson(list<Person> LP)
{
	for (list<Person>::iterator it = LP.begin(); it != LP.end(); it++)
	{
		cout << "name:" << (*it).name << "age:" << (*it).age << "height" << (*it).height << endl;
	}
}

//原来传不传引用都能够正常排序
//bool myComparePerson(Person p1,Person p2)
bool myComparePerson(Person &p1, Person &p2)
{
	//只按年龄
	//return p1.age > p2.age;
	//多条件排序
	if (p1.age > p2.age) {
		return true;
	}
	else if (p1.age == p2.age) {
		return p1.height > p2.height;
	};
	return false;
}

void test07()
{
	Person p1("小明", 18, 189);
	Person p2("小✿", 16, 165);
	Person p3("小张", 18, 170);
	Person p4("小芳", 20, 170);
	list<Person> L;
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.sort(myComparePerson);
	printPerson(L);
}

//删除自定义数据类型
void test08() {
	Person p1("小明", 18, 189);
	Person p2("小✿", 16, 165);
	Person p3("小张", 18, 170);
	Person p4("小芳", 20, 170);
	list<Person> L;
	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);

	L.remove(p4);
	//没有找到接受“Person”类型的左操作数的运算符(或没有可接受的转换)
	//list 1493行 if (*_First == _Val) 要重载 == 操作符
	printPerson(L);
}

int main(void)
{
	//test01();
	//test02();
	//test03();
	//test04();
	//test05();
	//test06();
	//test07();
	test08();
	return 0;
}