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
 *
 * Sort an array using bubble sort
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
 *
 * Sort an int array with selection sort
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
 *
 * Sort an int array with selection sort
 * written to find max and put in last place
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


/**
 * insertion_sort
 * @param elements an array of integers
 * @param size the length of elements
 *
 * Sort an int array with insertion sort
 */
void insertion_sort(int elements[], int size) {

    for(int start = 1; start < size; ++start) {

        int pos = start;
        while(pos > 0 && elements[pos] < elements[pos - 1]) {
            swap(elements[pos], elements[pos - 1]);
            --pos;
        }
    }

}
