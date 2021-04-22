/**
 *  @file factorial.cpp
 *
 *  Show regular and tail recursion via factorial.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>

/**
 * factorial
 * @param num factorial to compute (i.e., num!)
 *
 * Compute factorial of num (i.e., num!)
 * using regular recursion.
 *
 * @returns num!
 */
unsigned long long factorial(int num) {

    if(num <= 1) return 1;

    return num * factorial(num - 1);

}

/**
 * factorial_tail
 * @param num factorial to compute (i.e., num!)
 * @param product running product for factorial
 *
 * Compute factorial of num (i.e., num!)
 * using tail recursion.
 *
 * @returns num!
 */
unsigned long long factorial_tail(int num, unsigned long long product) {

    if(num <= 1) return product;

    return factorial_tail(num - 1, num * product);

}

/**
 * factorial_tail
 * @param num factorial to compute (i.e., num!)
 *
 * Compute factorial of num (i.e., num!)
 * using tail recursion.
 *
 * @returns num!
 */
unsigned long long factorial_tail(int num) {

    return factorial_tail(num, 1);

}

int main(int argc, char * argv[]) {

    std::cout << "factorial(0):       " << factorial(0)  << '\n';
    std::cout << "factorial(1):       " << factorial(1)  << '\n';
    std::cout << "factorial(5):       " << factorial(5)  << '\n';
    std::cout << "factorial(20):      " << factorial(20) << '\n';

    std::cout << "factorial_tail(0):  " << factorial_tail(0)  << '\n';
    std::cout << "factorial_tail(1):  " << factorial_tail(1)  << '\n';
    std::cout << "factorial_tail(5):  " << factorial_tail(5)  << '\n';
    std::cout << "factorial_tail(20): " << factorial_tail(20) << '\n';

    return 0;
}
