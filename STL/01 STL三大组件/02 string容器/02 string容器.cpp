#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//3.1.2.1 string 构造函数
//string();//创建一个空的字符串 例如: string str;
//string(const string& str);//使用一个string对象初始化另一个string对象
//string(const char* s);//使用字符串s初始化
//string(int n, char c);//使用n个字符c初始化

//3.1.2.2 string基本赋值操作
//string& operator=(const char* s);//char*类型字符串 赋值给当前的字符串
//string& operator=(const string &s);//把字符串s赋给当前的字符串
//string& operator=(char c);//字符赋值给当前的字符串
//string& assign(const char *s);//把字符串s赋给当前的字符串
//string& assign(const char *s, int n);//把字符串s的前n个字符赋给当前的字符串
//string& assign(const string &s);//把字符串s赋给当前字符串
//string& assign(int n, char c);//用n个字符c赋给当前字符串
//string& assign(const string &s, int start, int n);//将s从start开始n个字符赋值给字符串

void test01() {
	string s;
	string s1(s);
	string s2("hello");
	string s3(10, 'a');
}

//char& operator[](int n);//通过[]方式取字符
//char& at(int n);//通过at方法获取字符
void test02()
{
	string s = "hello world";
	for (int i = 0; i < s.size(); i++)
	{
		cout << s[i] << endl;
		cout << s.at(i) << endl;
	}
	//[]和at区别? []访问越界 直接挂掉(打断点不会走catch) at会抛出异常
	//cout << s[100] << endl;
	//cout << s.at(100) << endl;

	try
	{
		cout << s[100] << endl;
		//cout << s.at(100) << endl;
	}
	catch (const std::exception&)
	{
		cout << "异常" << endl;
	}
}

//string& operator+=(const string& str);//重载+=操作符
//string& operator+=(const char* str);//重载+=操作符
//string& operator+=(const char c);//重载+=操作符
//string& append(const char *s);//把字符串s连接到当前字符串结尾
//string& append(const char *s, int n);//把字符串s的前n个字符连接到当前字符串结尾
//string& append(const string &s);//同operator+=()
//string& append(const string &s, int pos, int n);//把字符串s中从pos开始的n个字符连接到当前字符串结尾
//string& append(int n, char c);//在当前字符串结尾添加n个字符c
void test03()
{
}

//int find(const string& str, int pos = 0) const; //查找str第一次出现位置,从pos开始查找
//int find(const char* s, int pos = 0) const;  //查找s第一次出现位置,从pos开始查找
//int find(const char* s, int pos, int n) const;  //从pos位置查找s的前n个字符第一次位置
//int find(const char c, int pos = 0) const;  //查找字符c第一次出现位置
//int rfind(const string& str, int pos = npos) const;//查找str最后一次位置,从pos开始查找
//int rfind(const char* s, int pos = npos) const;//查找s最后一次出现位置,从pos开始查找
//int rfind(const char* s, int pos, int n) const;//从pos查找s的前n个字符最后一次位置
//int rfind(const char c, int pos = 0) const; //查找字符c最后一次出现位置
//string& replace(int pos, int n, const string& str); //替换从pos开始n个字符为字符串str
//string& replace(int pos, int n, const char* s); //替换从pos开始的n个字符为字符串s
void test04()
{
}

/*
compare函数在>时返回 1，<时返回 -1，==时返回 0。
比较区分大小写，比较时参考字典顺序，排越前面的越小。
大写的A比小写的a小。
*/
//int compare(const string &s) const;//与字符串s比较
//int compare(const char *s) const;//与字符串s比较
void test05()
{
}

//string substr(int pos = 0, int n = npos) const;//返回由pos开始的n个字符组成的字符串
void test06()
{
}

//string& insert(int pos, const char* s); //插入字符串
//string& insert(int pos, const string& str); //插入字符串
//string& insert(int pos, int n, char c);//在指定位置插入n个字符c
//string& erase(int pos, int n = npos);//删除从Pos开始的n个字符
void test07()
{
}

//string和c-style字符串转换
void test08()
{
	//string 转 char*
	string str1 = "hello world";
	const char* cstr = str1.c_str();
	//char* 转 string
	const char *s = "nice to meet you";
	string str(s);

	cout << str1 << endl;
	cout << s << endl;
}

//大小写转换
void test09()
{
}

int main(void)
{
	//test01();
	//test02();

	test08();
	return 0;
}