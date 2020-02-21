/**
 * @file main.cpp
 *
 * Illustrates using the set ADT
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include <cassert>

#include "set.hpp"

int main(int argc, char * argv[]) {

    set empty;

    //set one_element(12);
    set one_element(MAX + MAX);

    empty = one_element;

    set multi_element{12, 50, 4, 9, 13, 40};
    set duplicate_set{12, 50, 4, 9, 13, 40};

    assert(multi_element == duplicate_set);
    //assert(multi_element == one_element);

    std::cout << multi_element << '\n';

    return 0;
}
