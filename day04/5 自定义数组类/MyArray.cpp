#include "stdafx.h"
#include "MyArray.h"
#include <iostream>

using namespace std;

MyArray::MyArray()
{
}

MyArray::MyArray(int len)
{
	this->length = len;
	this->space = new int[len];
}

MyArray::MyArray(const MyArray &another)
{
	if (another.length >= 0)
	{
		this->length = another.length;
		free(this->space);
		this->space = new int[another.length];
		for (int i = 0; i < another.length; i++) {
			this->space[i] = another.space[i];
		}
	}
}

int MyArray::getLen()
{
	return this->length;
}

void MyArray::setData(int index, int data)
{
	this->space[index] = data;
}

int MyArray::getData(int index)
{
	return this->space[index];
}


MyArray::~MyArray()
{
	if (this->space != NULL)
	{
		//delete this; CTODO 与下面三句效果有区别吗

		delete[] this->space;
		this->length = 0;
		this->space = NULL;

		cout << "MyArray::~MyArray() 被调用" << endl;
	}
}
