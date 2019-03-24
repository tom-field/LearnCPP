#include "stdafx.h"
#include "Dog.h"
#include <iostream>
using namespace std;

Dog::Dog()
{
	cout << "Dog()..." << endl;
}

void Dog::voice()
{
	cout << "Dog voice" << endl;
}

Dog::~Dog()
{
	cout << "~Dog()..." << endl;
}
