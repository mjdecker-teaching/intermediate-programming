/**
 * @file search.cpp
 *
 * Tests for linear and binary searches
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 * @date Spring 2021
 */

#include <iostream>
#include <cassert>

#include "search.hpp"

int main(int argc, char * argv[]) {

    int list[] = { 9001, 42, -1, 0x2A, 1048578 };

    assert(linear_search(list, 5, -1) == 3);

    return 0;
}
