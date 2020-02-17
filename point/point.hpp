/**
 *  @file point.hpp
 *
 *  Defined point class to illustrate basic classes.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#ifndef CS2_POINT_HPP
#define CS2_POINT_HPP

class point {
  // class defaults to private
  // struct default to public
  // if has more than just data, make it a class
private:
    // data members
    // private only members (constructors/methods)
    // can access
    // if public, anything can access
    // make private, protects access
    int x;
    int y;

public:
    // constructors, generally public
    point();
    point(int x, int y);

    // methods are generally public
  
    // getter methods
    // always need const version, so const object
    // can call method
    // may need non const
    int get_x() const;
    int get_y() const;

    // setter method
    void set_x(int x);
    void set_y(int y);

    point add(const point & other);
    point operator+(const point & other);
    // friend point operator+(point p, const point & rhs);

    int distance(const point & other);
    int operator-(const point & rhs);

    void print() const;

};

#endif
