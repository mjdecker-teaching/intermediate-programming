/**
 * @file search.cpp
 *
 * Implement linear and binary search.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 * @date Spring 2020
 */

#include "search.hpp"

/**
 * linear_search
 * @param elements an array of integers
 * @param size the length of elements
 * @param key integer to search elements for
 *
 * Searches through elements linearly for a provided key
 *
 * @returns first position of key in elements or -1
 *          if key is not in elements
 */
int linear_search(const int elements[], int size, int key) {

    for(int pos = 0; pos < size; ++pos) {
        if(elements[pos] == key) {
            return pos;
        }
    }

    return -1;
}

/**
 * binary_search
 * @param elements an array of integers
 * @param size the length of elements
 * @param key integer to search elements for
 *
 * @pre elements is in increasing sorted order
 *
 * Searches through elements  for a provided key
 * 
 * @returns position of a key in elements or -1
 *          if key is not in elements
 */
int binary_search(const int elements[], int size, int key) {

    int bottom = 0;
    int top = size - 1;

    while(bottom <= top) {

        int middle = (bottom + top) / 2;
        if(elements[middle] == key) {
            return middle;
        } else if(elements[middle] < key) {
            bottom = middle + 1;
        } else {
            top = middle - 1;
        }

    }

    return -1;
}


/**
 * binary_search_recursive_impl
 * @param elements an array of integers
 * @param key integer to search elements for
 * @param bottom starting index
 * @param top ending index
 *
 * @pre elements is in increasing sorted order
 *
 * Searches through elements for a provided key
 * uses recursion
 * 
 * @returns position of a key in elements or -1
 *          if key is not in elements
 */
int binary_search_recursive_impl(const int elements[], int key, int bottom, int top) {
    if(bottom > top) { return -1; }

    int middle = (bottom + top) / 2;
    if(elements[middle] == key) {
        return middle;
    } else if(elements[middle] < key) {
        return binary_search_recursive_impl(elements, key, middle + 1, top);
    } else {
        return binary_search_recursive_impl(elements, key, bottom, middle - 1);
    }
}

/**
 * binary_search_recursive
 * @param elements an array of integers
 * @param size the length of elements
 * @param key integer to search elements for 
 *
 * @pre elements is in increasing sorted order
 *
 * Searches through elements for a provided key
 * uses recursion
 * 
 * @returns position of a key in elements or -1
 *          if key is not in elements
 */
int binary_search_recursive(const int elements[], int size, int key) {
    return binary_search_recursive_impl(elements, key, 0, size - 1);
}
