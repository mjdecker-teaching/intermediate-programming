/**
 *  @file sum.cpp
 *
 *  This is a generic C++ main file.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>

int sum(int num) {
    if(num < 1) return -1;
    if(num == 1) return 1;
    return num + sum(num - 1);

}

int main(int argc, char * argv[]) {

    std::cout << sum(1000) << '\n';
    std::cout << sum(100) << '\n';
    std::cout << sum(-1) << '\n';

    return 0;
}
