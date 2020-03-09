/**
 * @file main.cpp
 *
 * This is a generic C++ main file.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#include <iostream>
#include "array.hpp"

int main(int argc, char * argv[]) {

    {
	darray array(10);

    } // array goes out scope and object goes way
    //darray array_2 = array;

    return 0;
}
