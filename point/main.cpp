/**
 *  @file main.cpp
 *
 *  Main class illustrate basic class usage through point class.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>
#include "point.hpp"

/**
 * ADT - Abstract Data Type = Mathematical model for data types
 *       Consists of:
 *       data
 *       operations on that data
 *       rules of usage
 *
 * classes used to realize an ADT
 *
 * information hiding - the interface
 *     (how you access/use something) is separated
 *     from how it is implemented.
 * encapsulation - bundling of data/methods and restricting of direct access to
 *     components
 *
 * A class is sort of like a black box.
 * information hiding is principle and encapsulation is the technique
 */

int main(int argc, char * argv[]) {

    // with no constructors an implicitly defined default constructor is created
    // When create a constructor the implicitly defined default is not created
  
    // Can't declare an array of an object without default constructor
    // point points[4];

    // can't access private x,y
    // access via . operator
    //point p;
    //p.x;
    //p.y;
  
    // show has random values (need a constructor)
    // initialize a object via a constructor
    // object is an instance of the class
    // all instances are separate from each other
    // calling one method on object runs on that instance only
    point default_init;
    // method also invoked called via . operator
    default_init.print();

    point start(-2, 1);
    start.print();

    point end(1, 5); 
    end.print();

    std::cout << '\n';

    // distance between points
    std::cout << "distance: " << start.distance(end) << '\n';

    std::cout << '\n';

    // add points (cleaner as method)
    std::cout << "sum: ";
    point sum = start.add(end);
    sum.print();

    // operator+
    std::cout << "op_call_sum: ";
    point op_call_sum = start.operator+(end);
    op_call_sum.print();

    std::cout << "op_sum: ";
    point op_sum = start + end;
    op_sum.print();

    // print this when called
    std::cout << "reverse: ";
    point reverse = end + start;
    reverse.print();

    std::cout << "temp_sum: ";
    point temp_sum = start + point(-1,-2);
    temp_sum.print();
    std::cout << "temp_sum: ";
    (start + point(-1,-2)).print();

    //operator-
    std::cout << '\n';
    std::cout << "distance: " << (start - end) << '\n';
    std::cout << "distance: " << (end - start) << '\n';

    // const object can only call const methods
    const point const_point(3, 4);
    
    
    point points[] =  { point(), point(1, 2), point(3, 3), point(5, 3) };
    int x_total = 0;
    for(int pos = 0; pos < 4; ++pos) {
        x_total += points[pos].get_x();
    }
    std::cout << "x total: " << x_total << '\n';

    
    return 0;
}
