/**
 * @file main.cpp
 *
 * Main file for triangle class.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 * @date 2/15/20
 */

#include <iostream>
#include <cassert>
#include "triangle.hpp"

int main() {

    // base = 3, height = 4, hypotenuse = 5
    const triangle default_triangle;

    std::cout << "default triangle perimeter: " << default_triangle.perimeter() << '\n';
    std::cout << "default triangle are: " << default_triangle.area() << '\n';

    assert(default_triangle.get_base() == 3.0);
    assert(default_triangle.get_height() == 4.0);
    assert(default_triangle.get_hypotenuse() == 5.0);


    // base height, hypotenuse
    triangle right_triangle(6.0, 8.0, 10.0);

    assert(right_triangle.perimeter() == 24.0);
    assert(right_triangle.area() == 24.0);

    right_triangle.set_base(3.0);
    right_triangle.set_height(4.0);
    right_triangle.set_hypotenuse(5.0);

    assert(right_triangle.get_base() == 3.0);
    assert(right_triangle.get_height() == 4.0);
    assert(right_triangle.get_hypotenuse() == 5.0);

    return 0;
}
