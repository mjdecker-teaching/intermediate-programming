/**
 * @file array.cpp
 *
 * Implementation file for an Array ADT
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#include "array.hpp"
#include <iostream>

darray::darray() : data(nullptr), cap(0) {
}

darray::darray(int cap) : cap(cap) {
    data = new int[cap];
}

darray::~darray() {
    delete[] data;
    std::cerr << "HERE: " << __FILE__ << ' ' << __FUNCTION__ << ' ' << __LINE__ << '\n';
    data = nullptr;
}

int darray::operator[](int pos) const {
    return data[pos];
}

int & darray::operator[](int pos) {
    return data[pos];
}


