/**
 * @file main.cpp
 *
 * Illustrate pointers and dynamic memory.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#include <iostream>

int main(int argc, char * argv[]) {

    int answer = 42;
    int * pointer2answer = &answer;

    std::cout << "answer: " << answer << '\n';
    std::cout << "pointer to answer: " << pointer2answer << '\n';
    std::cout << "*pointer2answer: " << *pointer2answer << '\n';
    std::cout << "pointer2answer[0]: " << pointer2answer[0] << '\n';

    int ar[] = {0, 1, 2};
    std::cout << "ar: " << ar << '\n';
    std::cout << "*ar: " << *ar << '\n';
    std::cout << "*(ar +  2): " << *(ar + 2) << '\n';

    int * data = new int;
    std::cout << data << '\n';

    int * data_array = new int[4096];
    std::cout << data_array << '\n';

    delete data;
    delete[] data_array;

    return 0;
}
