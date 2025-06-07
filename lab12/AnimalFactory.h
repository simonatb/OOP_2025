#pragma once
#include "Farm.h"

Animal* animalFactory() {
	int type;
	std::cin >> type;

	switch (type)
	{
	case 0: return new Dog();
	case 1: return new Cow();
	case 2: return new Cat();
	default:
		return nullptr;
		break;
	}
}

