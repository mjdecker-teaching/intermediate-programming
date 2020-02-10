/**
 * @file sort.hpp
 *
 * Header for bubble and selection sort.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 * @date Spring 2020
 */

#ifndef INCLUDED_SORT_HPP
#define INCLUDED_SORT_HPP

/**
 * bubble_sort
 * @param elements an array of integers
 * @param size the length of elements
 * @param key integer to search elements for
 *
 * Sort an array using bubble sort
 *
 * @returns first position of key in elements or -1
 *          if key is not in elements
 */
void bubble_sort(int elements[], int size);

/**
 * selection_sort
 * @param elements an array of integers
 * @param size the length of elements
 * @param key integer to search elements for
 *
 * @pre elements is in increasing sorted order
 *
 * Sort an int array with selection sort
 * 
 * @returns position of a key in elements or -1
 *          if key is not in elements
 */
void selection_sort(int elements[], int size);

/**
 * selection_sort_max
 * @param elements an array of integers
 * @param size the length of elements
 * @param key integer to search elements for
 *
 * @pre elements is in increasing sorted order
 *
 * Sort an int array with selection sort
 * written to find max and put in last place
 * 
 * @returns position of a key in elements or -1
 *          if key is not in elements
 */
void selection_sort_max(int elements[], int size);

#endif