#ifndef CS2_STACK_HPP
#define CS2_STACK_HPP

#include <cassert>

const int MAX_VALUES = 256;

template<typename type>
class stack {
private:
    int tos;
    type values[MAX_VALUES];

public:

    stack() : tos(-1) {}

    /** @pre non-full stack */
    void push(const type & object) {
	assert(!full());
	++tos;
	values[tos] = object;
    }

    /** @pre non-empty stack */
    void pop() {
	assert(!empty());
	--tos;
    }

    /** @pre non-empty stack */
    type top() const {
	assert(!empty());
	return values[tos];
    }

    /** @pre non-empty stack */
    type & top() {
	assert(!empty());
	return values[tos];
    }

    bool empty() const {
	return tos == -1;
    }

    bool full() const {
	return tos == (MAX_VALUES - 1);
    }

};

#endif
