// 01 MyArray.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

using namespace std;

template<class T>
class MyArray {
public:
	MyArray(int capacity) 
	{
		this->mCapacity = capacity;
		this->mSize = 0;
		//申请内存
		this->pAddr = new T[this->mCapacity];
	}
	MyArray(const MyArray<T>& arr)
	{
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		//申请内存空间
		this->pAddr = new T[this->mCapacity];
		//拷贝数据
		for (int i = 0; i < this->mSize; i++)
		{
			this->pAddr[i] = arr.pAddr[i];
		}
	}
	T& operator[](int index)
	{
		return this->pAddr[index];
	}
	MyArray<T> operator=(const MyArray<T>& arr)
	{
		if (this->pAddr != NULL) {
			delete[] this->pAddr;
		}
		this->mSize = arr.mSize;
		this->mCapacity = arr.mCapacity;
		//拷贝数据
		for (int i = 0; i < this->mSize; i++)
		{
			this->pAddr[i] = arr.pAddr[i];
		}
		return *this;
	}

	//如果定义成void PushBack(T& data)
	//则不能直接push右值,因为右值没法取引用 obj.PushBack(10);
	void PushBack(T& data)
	{
		//判断容器中是否有位置
		if (this->mSize >= this->mCapacity) {
			return;
		}
		//调用拷贝构造 = 操作符
		//1. 对象元素必须能够被拷贝;
		//2. 容器都是值寓意,而非引用寓意 向容器中放入的元素,都是放入的元素拷贝,而不是元素本身;
		//3. 如果元素的成员有指针 注意深拷贝和浅拷贝问题;
		this->pAddr[this->mSize] = data;
		this->mSize++;
	}

	//T&& 对右值取引用 obj.PushBack(10) 可以编译成功
	void PushBack(T&& data)
	{
		//判断容器中是否有位置
		if (this->mSize >= this->mCapacity) {
			return;
		}
		this->pAddr[this->mSize] = data;
		this->mSize++;
	}

	~MyArray()
	{
		if (this->pAddr != NULL)
		{
			delete[] this->pAddr;
		}
	}

public:
	//一共可以容下多少个与三俗
	int mCapacity;
	//当前数组有多少元素
	int mSize;
	//保存数据的首地址
	T * pAddr;
};


void test01()
{
	MyArray<int> myarray(20);
	myarray.PushBack(10);
	myarray.PushBack(20);
	myarray.PushBack(30);
	myarray.PushBack(40);
	for (int i = 0; i < myarray.mSize; i++)
	{
		cout << myarray[i] << " ";
	}
	cout << endl;
}

void test02()
{
	class Person {};
	Person p1, p2;
	MyArray<Person> arr(10);
	arr.PushBack(p1);
	arr.PushBack(p2);

}

int main()
{
	test01();
	test02();
    return 0;
}

