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

#include "sort.hpp"

const int ARRAY_SIZE = 30000;
const int INT_MOD = 10000;
std::array<int, ARRAY_SIZE> generate_random_array() {

    srandom(std::time(nullptr));

    std::array<int, ARRAY_SIZE> elements;
    for(int i = 0; i < ARRAY_SIZE; ++i) {
        elements[i] = random() % INT_MOD;
    }

    return elements;

}

void time_call(const std::function<void (int elements[], int size)> & sort_func, int elements[ARRAY_SIZE]) {
    std::clock_t c_start = std::clock();
    auto start = std::chrono::high_resolution_clock::now();

    sort_func(elements, ARRAY_SIZE);

    std::clock_t c_end = std::clock();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "Time: " << std::chrono::duration<double, std::milli>(end - start).count() << '\n';
}

int main(int argc, char * argv[]) {

    std::array<int, ARRAY_SIZE> elements = generate_random_array();

    // std::sort(elements.begin(), elements.end());

    std::cout << "Bubble sort\n";
    time_call(bubble_sort, elements.data());

    std::cout << "\nSelection sort\n";
    time_call(selection_sort, elements.data());

    std::cout << "\nSelection sort max\n";
    time_call(selection_sort_max, elements.data());


    return 0;
}

