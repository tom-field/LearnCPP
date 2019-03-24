#pragma once
#include "Animal.h"
class Dog :
	public Animal
{
public:
	Dog();
	virtual void voice();
	virtual ~Dog();
};

