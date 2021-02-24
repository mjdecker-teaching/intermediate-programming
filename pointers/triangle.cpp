#include "triangle.hpp"

triangle::triangle(double base, double height, double hypotenuse) {
	this->base = new double(base);
	this->height = new double(height);
	this->hypotenuse = new double(hypotenuse);
}

double triangle::area() const {
    return 0.5 * (*base) * (*height);
}

double triangle::perimeter() const {
    return *height + *base + *hypotenuse;
}

void triangle::set_height(double height) {
    delete this->height;
    this->height = new double(height);   
}

void triangle::set_base(double base) {
    delete this->base;
    this->base = new double(base);
}

void triangle::set_hypotenuse(double hypotenuse) {
    delete this->hypotenuse;
    this->hypotenuse = new double(hypotenuse);
}

double triangle::get_height() const {
    return *height;
}

double triangle::get_base() const {
    return *base;
}

double triangle::get_hypotenuse() const {
    return *hypotenuse;
}

