/**
 * @file main.cpp
 *
 * This is a generic C++ main file.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 */

#include <iostream>
#include "point.hpp"

int main(int argc, char * argv[]) {

    const point p(3, 4);
    p.print();

    point apoint(42, 12);
    apoint.print();

    apoint.set_x(16);
    apoint.set_y(3);

    std::cout << "apoint.get_x() == " << apoint.get_x() << '\n';

    point points[] = { point(32, 64),
		       point(128, 256),
		       point(512, 1024),
		       point(2048, 4096),
		       point()
    };


    for(int pos = 0; pos < 5; ++pos) {
	points[pos].print();
    }

    //point new_point = p.add(apoint);
    point new_point = p + apoint;
    new_point.print();

    point location = p + apoint + new_point;

    //int distance = p.operator-(apoint);
    int distance = p - apoint;
    
    std::cout << "distance is " << distance << "\n";

    return 0;
}
