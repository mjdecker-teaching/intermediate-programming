/**
 * @file initializing.cpp
 *
 * Illustrative example to show why variables need initialized when first
 * declared
 *
 * Might work differently depending on compiler/build options
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#include <iostream>

void f() {

    int a = 42;
    std::cout << a << '\n';

}

void g() {

    // b has contents of what happened to be there (which is probably 42) and not 0
    int b;
    std::cout << b << '\n';

}

int main(int argc, char * argv[]) {

    f();
    g();

    return 0;
}
