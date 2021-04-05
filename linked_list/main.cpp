/**
 * @file main.cpp
 *
 * This is a generic C++ main file.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#include <iostream>
#include "dlist.hpp"

int main(int argc, char * argv[]) {

    list<int> int_list;

    int_list.insertBefore(42, int_list.begin());

    iterator<int> itr = int_list.begin();

    int_list.insertBefore(24, itr);
    int_list.insertBefore(349, itr);

    for(iterator<int> pos = int_list.begin(); pos != nullptr; ++pos) {
	std::cout << *pos << ' ';
    }
    std::cout << '\n';

    iterator<int> middle = int_list.begin();
    ++middle;
    int_list.remove(middle);

    for(iterator<int> pos = int_list.begin(); pos != nullptr; ++pos) {
	std::cout << *pos << ' ';
    }
    std::cout << '\n';

    
    return 0;
}
