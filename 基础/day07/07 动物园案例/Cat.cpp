#include "stdafx.h"
#include "Cat.h"
#include <iostream>
using namespace std;

Cat::Cat()
{
	cout << "Cat()..." << endl;
}

void Cat::voice()
{
	cout << "Cat voice" << endl;
}

Cat::~Cat()
{
	cout << "~Cat()..." << endl;
}
