/**
 * @file triangle.hpp
 *
 * Triangle class header
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#ifndef INCLUDED_TRIANGLE_HPP
#define INCLUDED_TRIANGLE_HPP

class triangle {
private:
	double * base;
	double * height;
	double * hypotenuse;

public:

	triangle(double base = 3, double height = 4, double hypotenuse = 5);
        triangle(const triangle & other);
        ~triangle();

        triangle & operator=(triangle);
    
	double get_base() const;
	double get_height() const;
	double get_hypotenuse() const;

	void set_base(double base);
	void set_height(double height);
	void set_hypotenuse(double hypotenuse);

	double perimeter() const;
	double area() const;


};


#endif
