/**
 * @file search.hpp
 *
 * Header for lineary and recursive and non-recursive searches.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 * @date Spring 2020
 */

#ifndef INCLUDED_SEARCH_HPP
#define INCLUDED_SEARCH_HPP

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
int linear_search(const int elements[], int size, int key);

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
int binary_search(const int elements[], int size, int key);


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
int binary_search_recursive_impl(const int elements[], int key, int bottom, int top);

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
int binary_search_recursive(const int elements[], int size, int key);

#endif