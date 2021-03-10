/**
 *  @file main.cpp
 *
 *  This is a generic C++ main file.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>
#include "array.hpp"

int main() {

    darray<int> d(752);

    darray<int> copy(d);
    darray<int> copy_two = d;

    copy = d;
    d = d;

    darray<int> d2(3);

    d2.reset_capacity(7);
    d2.reset_capacity(2);

    std::cerr << d2 << '\n';

    darray<double> e(752.0);

    return 0; // destructor called for d copy
}
