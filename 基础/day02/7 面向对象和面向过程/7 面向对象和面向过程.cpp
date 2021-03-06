// 7 面向对象和面向过程.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class Dog
{
public:

	void eat(const char *food)
	{
		cout << name << "吃了" << food << endl;
	}
	char name[64];
};

//面向过程是写一个过程，
void eat(Dog &dog, const char *food)
{
	cout << dog.name << "吃了" << food << endl;
}

int main(void)
{
	//如果是面向对象
	Dog dog;

	strcpy_s(dog.name, "狗");
	//dog.name = {'狗'}; //  TODO为什么不行
	//通过对象作为主驱动
	dog.eat("翔");

	//如果是面向过程
	eat(dog, "翔");

	//char name[64] = "狗";
	//char name2[64] = { '我','是' };
	//cout << name << endl;

	return 0;
}

