/**
 * @file enum.cpp
 *
 * Illustrates an enumerated type
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 * @date 2/10/20
 */

#include <iostream>

enum color {
    RED,
    GREEN,
    BLUE,
    ORANGE,
    PURPLE = 42,

};

int main(int argc, char * argv[]) {

    color red = RED;
    std::cout << red << '\n';
    std::cout << GREEN << '\n';
    std::cout << BLUE << '\n';
    std::cout << PURPLE << '\n';
    std::cout << BLUE + GREEN << '\n';

    return 0;
}
