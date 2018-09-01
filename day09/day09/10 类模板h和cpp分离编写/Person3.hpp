#include "stdafx.h"
#include "Person3.h"
#include <iostream>

using namespace std;

template<class T>
Person3<T>::Person3(T age)
{
	this->age = age;
}

template<class T>
Person3<T>::~Person3()
{

}
template<class T>
void Person3<T>::Show()
{
	cout << "Age:" << this->age << endl;
}