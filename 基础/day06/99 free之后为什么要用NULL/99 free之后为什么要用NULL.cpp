// 99 free之后为什么要用NULL.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdio.h>
#include <malloc.h>
#include <iostream>

using namespace std;

void test()
{
	int *p = NULL;
	p = (int *)malloc(sizeof(int));
	*p = 400;
	printf("free前，%d\n", *p);//输出400
							 //free(p);
							 //if (p != NULL)
							 //printf("free后，未设置NULL，%d\n", *p);//可能输出1497144或其他的垃圾值
	if (p != NULL)
	{
		printf("free后，设置NULL，%d\n", *p);//可能输出1497144或其他的垃圾值

		free(p);
		p = NULL;

		printf("free后，设置NULL");//可能输出1497144或其他的垃圾值
	}
}
int main(int argc, char *argv[])
{
	test();

	cout << "end" << endl;
		
	return 0;
}

