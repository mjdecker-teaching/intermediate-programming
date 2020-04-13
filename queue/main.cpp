/**
 *  @file main.cpp
 *
 *  This is to test stack class.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>
#include <string>
#include "queue_linked_list.hpp"

int main(int argc, char * argv[]) {

    queue<int> int_queue;
    int num = 1;
    while(true) {
        if(num == 4) break;
        int_queue.enqueue(num++);

        
    }

    while(!int_queue.is_empty()) {
        std::cout << "front: " << int_queue.front() << '\n';
        int_queue.dequeue();
    }

    while(true) {
        if(num == 4) break;
        int_queue.enqueue(num++);
    }

    while(!int_queue.is_empty()) {
        std::cout << "front: " << int_queue.front() << '\n';
        int_queue.dequeue();
    }

    std::cout << "\n\n";

    queue<int> two;

    two.enqueue(1);
    std::cout << "front: " << two.front() << '\n';
    two.enqueue(2);
    std::cout << "front: " << two.front() << '\n';
    two.dequeue();
    std::cout << "front: " << two.front() << '\n';
    two.enqueue(3);
    std::cout << "front: " << two.front() << '\n';
    two.enqueue(4);
    std::cout << "front: " << two.front() << '\n';
    two.dequeue();
    std::cout << "front: " << two.front() << '\n';
    two.enqueue(5);
    std::cout << "front: " << two.front() << '\n';
    two.enqueue(6);
    std::cout << "front: " << two.front() << '\n';
    std::cout << '\n';
    two.dequeue();
    std::cout << "front: " << two.front() << '\n';
    two.dequeue();
    std::cout << "front: " << two.front() << '\n';
    two.dequeue();
    std::cout << "front: " << two.front() << '\n';
    two.dequeue();
    std::cout << "is_empty: " << std::boolalpha << two.is_empty() << '\n';

    return 0;
}
