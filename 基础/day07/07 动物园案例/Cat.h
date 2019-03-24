#pragma once
#include "Animal.h"
class Cat :
	public Animal
{
public:
	Cat();
	virtual void voice();
	virtual ~Cat();
};

