/**
 * @file main.cpp
 *
 * This is a generic C++ main file.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include <string>

struct point {
    int x;
    int y;
};

struct array {
    int size;
    int * elements;
};

int main(int argc, char * argv[]) {

    point p = {3, 4};

    std::cout << "x = " << p.x << '\n';
    std::cout << "y = " << p.y << '\n';

    const int size = 5;
    int elements[] = {4, 42, 16, 13, 9001};
    array data = { size, elements };

    for(int i = 0; i < data.size; ++i) {
	std::cout << data.elements[i] << '\n';
    }

    return 0;
}
