/**
 * @file point.cpp
 *
 * Implements a point ADT
 *
 * @author Michael Decker, Ph.D.
 * @data 2/14/20
 */

#include "point.hpp"
#include <iostream>
#include <cmath>

point::point() : point(0, 0) {}

point::point(int x, int y)
    : x(x), y(y) {
    //this->x = x;
    ///this->y = y;
}

int point::get_x() const {
    return x;
}

int point::get_y() const {
    return y;
}

void point::set_x(int new_x) {
    x = new_x;
}

void point::set_y(int new_y) {
    y = new_y;
}

void point::print() const {
    std::cout << "x: " << x << " y: " << y << '\n';
}

point point::add(const point & other) const {
    point result;

    // x belongs is the object this method was called on
    result.x = x + other.x;
    result.y = y + other.y;

    return result;
}

// add is called on current object
// (i.e., this)
point point::operator+(const point & other) const {
    return add(other);
}

// calculate euclidean distance between two points
int point::operator-(const point & rhs) const {
    int x_diff = x - rhs.x;
    int y_diff = y - rhs.y;

    int result = std::sqrt(x_diff * x_diff
			   + y_diff * y_diff);
    return result;

}
