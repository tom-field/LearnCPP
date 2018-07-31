#pragma once
#include <iostream>

using namespace std;

class MyArray
{
public:
	//无参构造函数
	MyArray();

	//在给数组初始化的时候，开辟多少个元素空间
	MyArray(int len);

	//拷贝构造函数
	MyArray(const MyArray& another);

	int getLen();

	//index 代表要赋值的数组的下标, data 数据
	void setData(int index, int data);

	int getData(int index);

	~MyArray();

private:
	int length; //数组目前的元素个数
	int *space; //space 是在堆上开辟数组空间的首元素地址。
};

