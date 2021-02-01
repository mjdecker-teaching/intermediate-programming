/**
 * @file struct.cpp
 *
 * Illustrates struct as plain-old-data
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#include <iostream>
#include <string>

// Creates a new user-defined-type `person`
// Person stores the data you specify (it is also stored consecutively like an array)
// This definition has a: first name, last name, and age
struct person {

    std::string first_name;
    std::string last_name;

    int age;
        
};


// Passing to functions - person is a type like you would put int or double
// Generally do so by reference (when need to write to it) or const reference (read-only)
// Passing-by-value reference (also read-only) creates complete copy of all its data (costly),
// there are instances you may want this, but const reference is preferred 
void print_person(const person & a_person) {
    std::cout << "Name: " << a_person.first_name << " " << a_person.last_name << '\n';
    std::cout << " Age:" << a_person.age << '\n';
    std::cout << '\n';
}


int main(int argc, char * argv[]) {

    // person - allocates space for two strings and 1 int
    /* struct */ person sue;

    // Can access (read or write/assign) to each data item in person by name
    // Accessed through variable name with . operator (can be whitespace before/after .)
    // Do not try to use person to access
    sue.first_name = "sue";
    sue.last_name = "cash";
    sue.age = 42;

    // Can also assign when initalized using {} similar to an array
    // Goes in order defined in person: first_name = johnny, second_name = cash, age = 71
    person johnny = { "johnny", "cash", 71};


    // parallel arrays
    std::string first_names[4] = {"john", "paul", "george", "ringo"};
    std::string last_names[4]  = {"lennon", "mccartney", "harrison", "starr"};
    int age[4]                 = { 27, 25, 24, 27 };

    // to update a person with parrallel arrays
    // error prone as need to know/remember all that exist and update all consistently
    first_names[3] = "pete";
    last_names[3] = "best";
    age[3] = 26;
       
    // person array
    person persons[4] = { { "john", "lennon", 27     }, { "paul", "mccartney", 25 },
                          { "george", "harrison", 24 }, { "ringo", "starr", 27    } };

    // access all data through person struct
    persons[3].first_name = "pete";
    persons[3].last_name = "best";
    persons[3].age = 26;

    // can do this, but a little strange, and we will learn something better later
    persons[3] = (person){ "pete", "best", 26 };

    //  each data item
    persons[3].age = 79;

    // function call on struct
    print_person(sue);
    print_person(persons[0]);
    
    return 0;
}
