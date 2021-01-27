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
 *
 * Sort an array using bubble sort
 */
void bubble_sort(int elements[], int size);

/**
 * selection_sort
 * @param elements an array of integers
 * @param size the length of elements
 *
 * Sort an int array with selection sort
 */
void selection_sort(int elements[], int size);

/**
 * selection_sort_max
 * @param elements an array of integers
 * @param size the length of elements
 *
 * Sort an int array with selection sort
 * written to find max and put in last place
 */
void selection_sort_max(int elements[], int size);


/**
 * insertion_sort
 * @param elements an array of integers
 * @param size the length of elements
 *
 * Sort an int array with insertion sort
 */
void insertion_sort(int elements[], int size);

#endif