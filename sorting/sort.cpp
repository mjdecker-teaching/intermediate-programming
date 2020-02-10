/**
 * @file sort.cpp
 *
 * Implementation of bubble and selection sort.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 * @date Spring 2020
 */

void swap(int & lhs, int & rhs) {
    int temp = lhs;
    lhs = rhs;
    rhs = temp;
}

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
void bubble_sort(int elements[], int size) {

    for(int length = size - 1; length > 0; --length) {
        for(int pos = 0; pos < length; ++pos) {
            if(elements[pos] > elements[pos + 1]) {
                swap(elements[pos], elements[pos + 1]);
            }
        }
    }

}

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
void selection_sort(int elements[], int size) {

    for(int start = 0; start < size - 1; ++start) {

        int min_pos = start;
        int min_element = elements[start];
        for(int pos = start + 1; pos < size; ++pos) {
            if(elements[pos] < min_element) {
                min_pos = pos;
                min_element = elements[pos];
            }
        }
        swap(elements[start], elements[min_pos]);
    }

}

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
void selection_sort_max(int elements[], int size) {

    for(int length = size - 1; length > 0; --length) {

        int max_pos = length;
        int max_element = elements[length];
        for(int pos = length - 1; pos >= 0; --pos) {
            if(elements[pos] > max_element) {
                max_pos = pos;
                max_element = elements[pos];
            }
        }
        swap(elements[max_pos], elements[length]);
    }
}
