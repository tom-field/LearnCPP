// 05 如何定义一个数组指针.cpp: 定义控制台应用程序的入口点。
//
// CTODO 定义的数组指针赋值
#include "stdafx.h"
#include <iostream>
using namespace std;

typedef int(ARRAY_SIZE_10)[10];
typedef int(* P_ARRAY_SIZE_10)[10];

int main()
{
	ARRAY_SIZE_10 testArray;
	for (int i = 0; i < 10; i++)
	{
		testArray[i] = i;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << testArray[i] << endl;
	}
	P_ARRAY_SIZE_10 parray = NULL;
#if 1
	for (int i = 0; i < 10; i++)
	{
		int a = i;
		parray[i] = &a;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << parray[i] << endl;
	}
#endif // 0

	int *p = new int[1000];

	p[0] = 10;

	p[1] = 20;

	cout << p[1] << endl;

	int a = 7;
	int *p2 = &a;
	cout << *p2 << endl;
    return 0;
}

