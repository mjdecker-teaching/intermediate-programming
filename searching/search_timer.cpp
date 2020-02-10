/**
 * @file search_timer.hpp
 *
 * Present timings for auto generated arrays.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bsgu.edu>
 * @date Spring 2020
 */

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <functional>
#include <array>
#include <chrono>
#include <algorithm>

#include "search.hpp"

const int ARRAY_SIZE = 1000000;
const int INT_MOD = 10000;
std::array<int, ARRAY_SIZE> generate_random_array() {

    srandom(std::time(nullptr));

    std::array<int, ARRAY_SIZE> elements;
    for(int i = 0; i < ARRAY_SIZE; ++i) {
        elements[i] = random() % INT_MOD;
    }

    std::sort(elements.begin(), elements.end());

    return elements;

}

const int NUM_CALLS = 1000;
void time_call(const std::function<int (const int elements[], int size, int key)> & search_func, int elements[ARRAY_SIZE], int key) {
    std::clock_t c_start = std::clock();
    auto start = std::chrono::high_resolution_clock::now();

    for(int i = 0; i < NUM_CALLS; ++i) {
       search_func(elements, ARRAY_SIZE, key);
    }

    std::clock_t c_end = std::clock();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time: " << std::chrono::duration<double, std::milli>(end - start).count() << '\n';
}

int main(int argc, char * argv[]) {

    std::array<int, ARRAY_SIZE> elements = generate_random_array();

    std::cout << "Lineary search\n";
    time_call(linear_search, elements.data(), elements[0]);
    time_call(linear_search, elements.data(), elements[ARRAY_SIZE - 1]);
    time_call(linear_search, elements.data(), INT_MOD + 1);

    std::cout << "\nBinary search\n";
    time_call(binary_search, elements.data(), elements[0]);
    time_call(binary_search, elements.data(), elements[ARRAY_SIZE - 1]);
    time_call(binary_search, elements.data(), INT_MOD + 1);

    std::cout << "\nBinary recursive search\n";
    time_call(binary_search_recursive, elements.data(), elements[0]);
    time_call(binary_search_recursive, elements.data(), elements[ARRAY_SIZE - 1]);
    time_call(binary_search_recursive, elements.data(), INT_MOD + 1);


    return 0;
}

