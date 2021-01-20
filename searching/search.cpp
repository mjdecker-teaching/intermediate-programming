/**
 * @file search.cpp
 *
 * Implement linear and binary search.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 * @date Spring 2020
 */

#include "search.hpp"

int linear_search(const int elements[], int size, int key) {

    for(int pos = 0; pos < size; ++pos)
        if(elements[pos] == key) {
            return pos;
        }
    }
    return -1;

    int pos = 0;
    while(pos < size) {
        if(elements[pos] == key) {
            return pos;
        }
        ++pos;
    }
    return -1;
}