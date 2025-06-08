#pragma once
#include <iostream>

class Animal {
public:
	virtual void sound() const = 0;
	virtual Animal* clone() const = 0;
	virtual int getType() const = 0;
	virtual ~Animal() = default;
};

class Cow : public Animal {
public:
	void sound() const override {
		std::cout << "Moo Moo" << std::endl;
	}
	Animal* clone() const override {
		return new Cow(*this);
	}
	int getType() const override {
		return 1;
	}
};

class Cat : public Animal {
public:
	void sound() const override {
		std::cout << "Meow Meow" << std::endl;
	}
	Animal* clone() const override {
		return new Cat(*this);
	}
	int getType() const override {
		return 2;
	}
};

class Dog : public Animal {
public:
	void sound() const override {
		std::cout << "Bau Bau" << std::endl;
	}
	Animal* clone() const override {
		return new Dog(*this);
	}
	int getType() const override {
		return 0;
	}
};

class Farm {
private:
	Animal** farm;
	size_t capacity;
	size_t count;

	void copyFrom(const Farm& other);
	void moveFrom(Farm&& other) noexcept;
	void free();

public:
	Farm();
	Farm(const Farm& other);
	Farm(Farm&& other) noexcept;
	Farm& operator=(const Farm& other);
	Farm& operator=(Farm&& other) noexcept;
	~Farm();

	void addAnimal(Animal* animal);
	void addAnimal(const Animal* animal);
	void resize();

	void roarAll() const;

};
