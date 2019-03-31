#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//初始化对组
void test01()
{
	pair<string, int> p("tom", 10);
	cout << p.first << endl;
	cout << p.second << endl;

	pair<string, int> p2 = make_pair("jerry", 10);
	cout << p2.first << endl;
	cout << p2.second << endl;
}

int main(void)
{
	test01();
	return 0;
}