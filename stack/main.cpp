/**
 * @file main.cpp
 *
 * Shows use of stack class.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#include <iostream>
#include "stack.hpp"

class foo {
public:
	foo(int i = 0) {}

};

int main(int argc, char * argv[]) {

	stack<int> int_stack;

	int_stack.push(42);
	int_stack.push(11);
	int_stack.push(14);

	std::cout << "top = " << int_stack.top() << '\n';

	int_stack.pop();
	std::cout << "top = " << int_stack.top() << '\n';

	int_stack.pop();
	std::cout << "top = " << int_stack.top() << '\n';

	int_stack.push(7235);
	std::cout << "top = " << int_stack.top() << '\n';

	int_stack.push(-56);
	std::cout << "top = " << int_stack.top() << '\n';

	stack<double> double_stack;

	double_stack.push(3.14);
	std::cout << double_stack.top() << '\n';

	stack<foo> foo_stack;


    return 0;
}
