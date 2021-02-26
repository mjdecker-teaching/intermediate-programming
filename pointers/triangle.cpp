#include "triangle.hpp"

#include <iostream>

triangle::triangle(double base, double height, double hypotenuse) {
    this->base = new double(base);
    this->height = new double(height);
    this->hypotenuse = new double(hypotenuse);
}

triangle::triangle(const triangle & other) {
    base = new double(*other.base);
    height = new double(other.get_height());
    hypotenuse = new double(other.get_hypotenuse());
}

triangle::~triangle() {
    std::cerr << "HERE: " << __FILE__ << ' ' << __FUNCTION__ << ' ' << __LINE__ << '\n';
    delete base;
    delete height;
    delete hypotenuse;
}

void triangle::swap(triangle & other) {
    double * temp_base = base;
    base = other.base;
    other.base = temp_base;

    double * temp_height = height;
    height = other.height;
    other.height = temp_height;

    double * temp_hypotenuse = hypotenuse;
    hypotenuse = other.hypotenuse;
    other.hypotenuse = temp_hypotenuse;
    
}

triangle & triangle::operator=(triangle other) {
    swap(other);
    return *this;
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
