/**
 * @file point.hpp
 *
 * Illustrate classes via a point class.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#ifndef INCLUDED_POINT_HPP
#define INCLUDED_POINT_HPP

class point {
private:
    int x;
    int y;
public:
    point();
    point(int x, int y);

    int get_x() const;
    int get_y() const;

    void set_x(int new_x);
    void set_y(int new_y);

    void print() const;

    point add(const point & other) const;
    point operator+(const point & other) const;

    int operator-(const point & other) const;

};


#endif
