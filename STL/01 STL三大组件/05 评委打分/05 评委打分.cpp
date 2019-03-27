#define _CRT_SECURE_NO_WARNINGS

#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
#include <numeric>
#include <ctime>

using namespace std;
/*
	有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。
	//1. 创建五名选手，放到vector中
	//2. 遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
	//3. sort算法对deque容器中分数排序，pop_back pop_front去除最高和最低分
	//4. deque容器遍历一遍，累加分数，累加分数/d.size()
	//5. person.score = 平均分
*/

class Person
{
public:
	Person(string name)
	{
		this->m_name = name;
		this->m_score = 0;
	};
	~Person() 
	{

	};
	string m_name;
	int m_score;
};

//生成5名选手
void createPlayers(vector<Person> &Persons) {
	string names = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "player" + names[i];
		Person p = Person(name);
		Persons.push_back(p);
	}
}
// 评委打分
void gradePlayers(vector<Person> &Persons) {
	//创建1个deque容器
	for (vector<Person>::iterator it = Persons.begin(); it !=  Persons.end(); it++)
	{
		deque<int> scores;
		//评委打分
		for (int i = 0; i < 10; i++)
		{
			int score = rand() % 41 + 60;
			scores.push_back(score);
		}
		//排序后 去除最低分和最高分
		sort(scores.begin(), scores.end());
		scores.pop_back();
		scores.pop_front();
		//输出打分
		for (deque<int>::iterator it = scores.begin(); it != scores.end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
		//计算总分
		int sum = accumulate(scores.begin(), scores.end(), 0);
		(*it).m_score = sum / scores.size();
	}
}

int main(void)
{
	//只用初始化一次
	//srand((unsigned int)time(NULL));

	vector<Person> Persons;

	createPlayers(Persons);

	gradePlayers(Persons);

	for (vector<Person>::iterator it = Persons.begin(); it != Persons.end(); it++)
	{
		cout << "选手" << (*it).m_name << ": " << (*it).m_score << endl;
	}

	return 0;
}
