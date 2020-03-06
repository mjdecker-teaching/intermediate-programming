/**
 * @file main.cpp
 *
 * Illustrate pointers and dynamic memory.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#include <iostream>
#include <string>

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

/*
    // no delete run out of memory
    // When memory that is no longer needed is not released (deleted)
    // you get a memory leak
    while(true) {

	int * data = new int[100000000];
	delete[] data;
    }
*/

    // points to random address
    int * datum;
    std::cout << "datum: " << datum << '\n';
    // can't delete of not owned memory
    // delete datum;

    // To indicate not set use
    // one of following
    // What we did in C
    // NULL is macro for 0
    datum = 0;
    datum = NULL;

    // as of C++11 this is prefered method
    // NULL also updated to be nullptr
    // stronger type support
    datum = nullptr;
    std::cout << "datum: " << datum << '\n';

    std::string * dstr = new std::string("hello");

    // . is member access
    // but since don't have a class or struct
    // but a pointer, it does not work
    //std::cout << dstr.size() << '\n';

    // You need to dereference first
    // to get access to struct/class
    // then you can do member access
    std::cout << (*dstr).size() << '\n';

    // This is so common
    // (and because it looks ugly)
    // there is a special operator
    // that is equivalent to (*var).
    // -> operator
    std::cout << dstr->size() << '\n';

    // Remeber inside class/struct
    // method/constructor this is a keyword
    // which is pointer to current object
    // can't show here because not in class

    return 0;
}
