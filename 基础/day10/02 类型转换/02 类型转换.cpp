// 02 类型转换.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Building {};
class Animal {};
class Cat : public Animal {};

//static_cast
void test01() 
{
	//转换基础数据类型
	int a = 97;
	char c = static_cast<char>(a);

	char b = 'b';
	int d = static_cast<int>(b);

	cout << c << endl;
	cout << d << endl;


	//转换指针

	//基础数据类型指针 无法转换报错
	//int *p = NULL;
	//char *sp = static_cast<char*>(p);

	//对象指针 无继承关系 报错无法转换
	//Building* building = NULL;
	//Animal* ani = static_cast<Animal*>(building);

	//转换具有继承关系的对象指针
	//对象指针 有继承关系
	Animal* ani = NULL;
	Cat* cat = static_cast<Cat*>(ani);

	Cat* cat2 = NULL;
	Animal* ani2 = static_cast<Animal*>(cat2);

	//具有继承关系的引用类型转换
	Animal ani3;
	Animal& aniref = ani3;
	Cat& catref = static_cast<Cat&>(aniref);

	Cat catobj;
	Cat& catref2 = catobj;
	Animal& aniref2 = static_cast<Animal&>(catref2);

	//总结:
	//static_cast 用于内置的数据类型;
	//还有具有继承关系的指针或者引用;
}

//dynamic_cat 动态类型转换
//转换具有继承关系的,在转换前会对对象类型进行类型检查
void test02()
{
	//转换基础数据类型 报错 不能转换
	//int a = 97;
	//char c = dynamic_cast<char>(a);
	//非继承关系的指针或者应用 报错无法转换
	//Building* building = NULL;
	//Animal* ani = dynamic_cast<Animal*>(building);
	//有继承关系的指针或者引用 //报错原因 做类型安全检查 把小箱子转化为大箱子 就不安全了
	//把父类指针转化为子类指针 子类是大于等于父类的,转化后父类指针的寻址空间变大,会有访问越界隐患
	//Animal* ani = NULL;
	//Cat* cat = dynamic_cast<Cat*>(ani);
	
	Cat* cat2 = NULL;
	Animal* ani2 = dynamic_cast<Animal*>(cat2);

	//结论:
	//dynamic_cast只能转换具有继承关系的指针或者引用
	//并且只能由大到小转换,由子类转换为父类
}

//const_cast
//指针 引用 对象指针
void test03()
{
	//基础数据类型
	int a = 10;
	const int& b = a;
	//b = 20; 不能对b进行修改
	int& c = const_cast<int&>(b);
	c = 20;
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;

	const int* p = NULL;
	int* p2 = const_cast<int*>(p);

	int *p3 = NULL;
	const int* p4 = const_cast<int*>(p3);

	//char *sp = const_cast<char*>(p);

	//增加或者去除const属性
}

//reinterpret_cast 强制类型转换
void test04()
{
	//无关的类型都可以进行转换
	Building* building = NULL;
	Animal* ani = reinterpret_cast<Animal*>(building);

	typedef void(FUNC1)(int, int);
	typedef void(FUNC2)(int, char);

	FUNC1* func1 = NULL;
	FUNC2* func2 = reinterpret_cast<FUNC2*>(func1);
}

int main()
{
	//test01();
	//test02();
	//test03();
	test04();
    return 0;
}

