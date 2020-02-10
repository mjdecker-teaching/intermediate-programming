/**
 * @file search.cpp
 *
 * Tests for linear and binary searches
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 * @date Spring 2020
 */

#include <iostream>
#include <cassert>

#include "search.hpp"

int main(int argc, char * argv[]) {

    int empty[] = { };
    int single[] = { 1 };
    int sorted[] = { 1, 2, 7, 9 };
    int unsorted[] = { 9001, 42, -1, 0x2A, 1048576 };

    assert(linear_search(empty, 0, 1) == -1);
    assert(linear_search(single, 1, 1) == 0);

    assert(linear_search(sorted, 4, 7) == 2);
    assert(linear_search(sorted, 4, 9) == 3);
    assert(linear_search(sorted, 4, 1) == 0);

    assert(linear_search(sorted, 4, -1) == -1);
    assert(linear_search(sorted, 4, 11) == -1);
    assert(linear_search(sorted, 4, 3) == -1);

    assert(linear_search(unsorted, 4, 0x2A) == 1);

    assert(binary_search(empty, 0, 1) == -1);
    assert(binary_search(single, 1, 1) == 0);

    assert(binary_search(sorted, 4, 7) == 2);
    assert(binary_search(sorted, 4, 9) == 3);
    assert(binary_search(sorted, 4, 1) == 0);

    assert(binary_search(sorted, 4, -1) == -1);
    assert(binary_search(sorted, 4, 11) == -1);
    assert(binary_search(sorted, 4, 3) == -1);

    // should also boundary test a larger array of odd size

    assert(binary_search_recursive(empty, 0, 1) == -1);
    assert(binary_search_recursive(single, 1, 1) == 0);

    assert(binary_search_recursive(sorted, 4, 7) == 2);
    assert(binary_search_recursive(sorted, 4, 9) == 3);
    assert(binary_search_recursive(sorted, 4, 1) == 0);

    assert(binary_search_recursive(sorted, 4, -1) == -1);
    assert(binary_search_recursive(sorted, 4, 11) == -1);
    assert(binary_search_recursive(sorted, 4, 3) == -1);

    return 0;
}
