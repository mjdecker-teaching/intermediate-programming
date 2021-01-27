/**
 * @file test_sort.cpp
 *
 * Tests for bubble and selection sorts.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include <functional>

#include "sort.hpp"

void assert_sort(const std::function<void (int[], int)> & sort_func, const int input[], const int expected[], int size) {

    int elements[size];
    for(int pos = 0; pos < size; ++pos) {
        elements[pos] = input[pos];
    }

    sort_func(elements, size);

    for(int pos = 0; pos < size; ++pos) {
        assert(elements[pos] == expected[pos]);
    }

}

int main(int argc, char * argv[]) {

    int empty[] = { };
    int single[] = { 1 };

    int typical[] = { 9, 5, 12, 3, 7, 1 };
    int typical_sorted[] = { 1, 3, 5, 7, 9, 12 };
/*
    assert_sort(bubble_sort, empty, empty, 0);
    assert_sort(bubble_sort, single, single, 1);
    assert_sort(bubble_sort, typical, typical_sorted, 6);
*/
    assert_sort(selection_sort, empty, empty, 0);
    assert_sort(selection_sort, single, single, 1);
    assert_sort(selection_sort, typical, typical_sorted, 6);
/*
    assert_sort(selection_sort_max, empty, empty, 0);
    assert_sort(selection_sort_max, single, single, 1);
    assert_sort(selection_sort_max, typical, typical_sorted, 6);

*/
    assert_sort(insertion_sort, empty, empty, 0);
    assert_sort(insertion_sort, single, single, 1);
    assert_sort(insertion_sort, typical, typical_sorted, 6);

    return 0;
}
