// 9 为什么要有多态.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Yuebuqun
{
public:
	Yuebuqun(string kongfu) 
	{
		this->kongfu = kongfu;
	};
	~Yuebuqun() {};
	void fight()
	{
		cout << "Yuebuqun使出了" << kongfu << "打人" << endl;
	}
	virtual void fight2()
	{
		cout << "Yuebuqun使出了" << kongfu << "打人" << endl;
	}
	string kongfu;
private:

};

class Lingpingzhi : public Yuebuqun
{
public:
	Lingpingzhi(string kongfu) : Yuebuqun(kongfu)
	{
		
	};
	~Lingpingzhi() 
	{};
	void fight()
	{
		cout << "Lingpingzhi是出了" << kongfu << "大人" << endl;
	}
	virtual void fight2()
	{
		cout << "Lingpingzhi是出了" << kongfu << "大人" << endl;
	}
private:

};

void fightPeople(Yuebuqun *hero)
{
	hero->fight();
}
// 希望传递进来的如果是子类调用子类的fight 如果传入父类 调用父类的fight
void fightPeople2(Yuebuqun *hero)
{
	hero->fight2();
}

//多态发生的三个必要条件
//1.要有继承
//2.要有虚函数重写
//3.父类指针执向子类对象

int main()
{
	Yuebuqun *yy = new Yuebuqun("葵花宝典");
	Lingpingzhi *lpz = new Lingpingzhi("辟邪剑谱");

	fightPeople(yy);
	fightPeople(lpz);

	cout << "================" << endl;

	fightPeople2(yy);
	fightPeople2(lpz);

    return 0;
}

