// 06 大哥看场子.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//大哥的抽象类
class BigBrother
{
public:
	//想成为大哥 一定要会打人。
	virtual void fightPeople() = 0;
};

//东方不败
class EastNeverLost :public BigBrother
{
public:
	virtual void fightPeople()
	{
		cout << "使用葵花宝典打人" << endl;
	}
};

int main()
{
	//boss 知道有一个 大哥的职位 会打人
	BigBrother *bro = new EastNeverLost;

	//大哥你给我去打人
	bro->fightPeople();


	delete bro;
    return 0;
}

