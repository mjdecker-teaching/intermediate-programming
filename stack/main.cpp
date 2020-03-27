/**
 *  @file main.cpp
 *
 *  Illustrate stack class.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>
#include "stack.hpp"
#include <string>

int main(int argc, char * argv[]) {

    stack<int> int_stack;
    int_stack.push(42);
    int_stack.push(21);
    int_stack.push(7);
 
    std::cout << int_stack.top() << '\n';
    int_stack.pop();
    std::cout << int_stack.top() << '\n';
    int_stack.pop();
    std::cout << int_stack.top() << '\n';
    int_stack.pop();

    int_stack.push(12);
    std::cout << int_stack.top() << '\n';
    int_stack.pop();

    stack<std::string> str_stack;

    return 0;
}
