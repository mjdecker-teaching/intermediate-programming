/**
 *  @file shape.cpp
 *
 *  Show polymorhphism, overriding, and hiding.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */


#include <iostream>

class shape {

protected:
    int x;
    int y;

public:
    void move(int x, int y) { this->x = x; this->y = y; }
    virtual int area() = 0;
    virtual void draw() {}

};

class rectangle : public shape {

private:
    int width;
    int height;

public:
    rectangle(int w, int h) : width(w), height(h) {}
    int area() { std::cout << "rectangle: "; return width * height; }
    void draw() {  x = 0; }

};


class circle : public shape {
private:
    int radius;

public:
    circle(int r) : radius(r) {}
    int area() { std::cout << "circle: "; return (radius * radius * 22) / 7; }
    void draw() {}
  

};

int main(int argc, char * argv[]) {

    //shape s;
    rectangle r(3, 4);
    circle c(42);

    shape & s2 = r;

    s2.move(0, 1);
    r.move(5, 3);

    std::cout << r.area() << '\n';
    std::cout << c.area() << '\n';


    std::cout << s2.area() << '\n';

    return 0;
}
