/**
 * @file virtual.cpp
 *
 * Situations with virtual polymorphism, overriding, and hiding.
 *
 * @author Michael John Decker <mdecker6@kent.edu>
 * @author Michael L. Collard <collard@uakron.edu>
 */

#include <iostream>

class A {
public:
	virtual ~A() {}

	void go(int) { std::cout << "A::go(int)\n"; }

	void perform() { std::cout << "A::perform()\n"; }

	virtual void calculate() { std::cout << "A::calculate()\n"; }

};

class B : public A {
public:
	virtual ~B() {}

	virtual void go(int) { std::cout << "B::go(int)\n"; }
	virtual void go(char) { std::cout << "B::go(char)\n"; }

	virtual void calculate() { std::cout << "B::calculate()\n"; }

};

class C : public B {
public:
	virtual ~C() {}

	virtual void go(int) { std::cout << "C::go(int)\n"; }

	void perform() { std::cout << "C::perform()\n"; }

	virtual void calculate() { std::cout << "C::calculate()\n"; }

};

int main(int argc, char * argv[]) {

	A a; B b; C c;

	std::cout << "\na, b, c perform()\n";
	a.perform();
	b.perform();
	c.perform();

	std::cout << "\na, b, c go(int)\n";
	a.go(1);
	b.go(1);
	c.go(1);

	std::cout << "\na, b, c calculate()\n";
	a.calculate();
	b.calculate();
	c.calculate();

	std::cout << "\na, b, c go(char)\n";
	a.go('a');
	b.go('a');
	c.go('a');

	std::cout << "\nA & ra = a\n";
	{
		A & ra = a;
		ra.perform();
		ra.go(1);
		ra.go('a');
		ra.calculate();
	}

	std::cout << "\nA & ra = b\n";
	{
		A & ra = b;
		ra.perform();
		ra.go(1);
		ra.go('a');
		ra.calculate();
	}

	std::cout << "\nA & ra = c\n";
	{
		A & ra = c;
		ra.perform();
		ra.go(1);
		ra.go('a');
		ra.calculate();
	}

	std::cout << "\nB & rb = b\n";
	{
		B & rb = b;
		rb.perform();
		rb.go(1);
		rb.go('a');
		rb.calculate();
	}

	std::cout << "\nB & rb = c\n";
	{
		B & rb = c;
		rb.perform();
		rb.go(1);
		rb.go('a');
		rb.calculate();
	}

	std::cout << "\nC & rc = c\n";
	{
		C & rc = c;
		rc.perform();
		rc.go(1);
		rc.go('a');
		rc.calculate();
	}

    return 0;
}
