/**
 *  @file point.cpp
 *
 *  Implementation for class point.  Shows basic class usage.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include "point.hpp"
#include <iostream>
#include <cmath>

/**
 * point
 * 
 * default initialize point object
 *
 * Each class creates its own namespace of its own name
 * Must use namespace point:: so compiler knows point
 * (or any other constructor/method) is of that class
 *
 * : (which ends at {) is member initializion list
 * can call another constructor to (delegating constructor)
 */
point::point()
  : /*x(0), y(0)*/ point(0, 0) {
  // can initialize in body, but member initialization is prefered method 
  // x = 0;
  // y = 0;
}

/**
 * point
 * @param x x value
 * @param y y value
 * 
 * initialize point object with x and y value
 * can use same name as parameters when using
 * member intialization list
 */
point::point(int x, int y)
  : x(x), y(y) {}

/**
 * get_x
 *
 * Getter method that return x
 *  
 * @return objects x value
 */
int point::get_x() const {
    return x;
}

/**
 * get_y
 * 
 * Getter method that return y
 *
 * @returns objects y value
 */
int point::get_y() const {
    return y;
}

/**
 * set_x
 * @param x x value
 *
 * Setter method to set x
 *
 * set object x value to given x
 */
void point::set_x(int x) {
    // each constructor/method
    // has the access to the variable this (a keyword)
    // it is a pointer to the current object (the one it was called on)
    // In this case, I am using it to deferentiate between
    // this->x the class data member, and x the parameter
    this->x = x;

}

/**
 * set_y
 * @param y y value
 *
 * Setter method to set y
 *
 * set object y value to given y
 */

void point::set_y(int y) {

    this->y = y;

}

/**
 * add
 * @param rhs other point object to add
 *
 * adds two point objects
 * 
 * @returns the addition of both points
 */
point point::add(const point & rhs) {

    //point result(x + rhs.x, y + rhs.y);
    //return result;
    return point(x + rhs.x, y + rhs.y);

}

/**
 * operator+
 * @param rhs other point object to add
 *
 * adds two point objects
 * 
 * @returns the addition of both points
 */
point point::operator+(const point & rhs) {
// point operator+(point p, const point & rhs) {

    return add(rhs);
    // p.x += rhs.x;
    // p.y += rhs.y;
    // return p;
}

/**
 * distance
 * @param rhs other point object
 *
 * calculate distance between two points
 * 
 * @returns the distance
 */
int point::distance(const point & other) {

    int x_diff = x - other.x;
    int y_diff = y - other.y;

    return std::sqrt(x_diff * x_diff + y_diff * y_diff);

}


/**
 * operator-
 * @param rhs other point object
 *
 * calculate distance between two points
 * 
 * @returns the distance
 */
int point::operator-(const point & other) {

    return distance(other);

}

/**
 * print
 *
 * print out object
 */
void point::print() const {

    std::cout << "x: " << x << " y: " << y << '\n';

}
