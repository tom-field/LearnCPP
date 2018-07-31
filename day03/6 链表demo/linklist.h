#pragma once

//linklist.h������������ͷ�����
#include "stdafx.h"
#include <iostream>
using namespace std;

struct Info
{
	string name;	//����
	int id;		//ѧ��
};
//������
struct Node
{
	Info val;
	Node *next;
	Node(Info x) :val(x), next(NULL) {}
};


class LinkList
{
public:
	//���캯��
	LinkList();
	//������ͷ��������
	void InsertHead(Info val);
	//������
	void Insert(Info val, int pos);
	//ɾ�����
	void Remove(Info val);
	//�õ�������
	int Length();
	//������
	void Reverse();
	//���ҽ��λ��
	int Find(Info val);
	//��ӡ����
	void Print();
	//��������
	~LinkList();
private:
	Node * head;
	int length;
};