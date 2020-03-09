/**
 * @file array.hpp
 *
 * Header (interface) file for an Array ADT
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#ifndef INCLUDED_ARRAY_HPP
#define INCLUDED_ARRAY_HPP

class darray {
private:
    int * data;
    int cap;

public:

    // cap 0
    darray();

    // data with cap int
    darray(int);

    ~darray();

    int operator[](int) const;
    int & operator[](int);

};

#endif
