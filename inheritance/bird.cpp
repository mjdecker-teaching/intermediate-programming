/**
 * @file main.cpp
 *
 * This is a generic C++ main file.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <memory>

class bird {
// private is still only accessible by this class, use protected
// to allow children to also access
//private:
protected:
    std::string name;

public:
    bird(const std::string & name) : name(name) {}
    std::string get_name() { return name; };

    // virtual methods get an entry in a v-table which is
    // used at runtime to look up the correct method to call parent/child
    // adding = 0 makes pure virtual. A class with at least one pure virtual is an abstract class
    virtual double get_airspeed() = 0;

    // if dynamically allocate data in the class, declare the destructor as virtual as well
    virtual ~bird() {}
    
};

// specify a parent class with : public parent-class-name
// all methods and data are inherited (child class has that data and operations)
// private members of the based (parent class) can not be accessed in child class
// make them protected to access
class european_swallow : public bird {
private:
public:
    // use a parent constructor in member initialization list to
    // intialize that data
    european_swallow(const std::string & name) : bird(name) {}
    virtual double get_airspeed() { return 42; }

};

class african_swallow : public bird {
private:
    int number_of_coconuts;
    static const double load_factor;
public:
    african_swallow(const std::string name, int number_of_coconuts)
	: bird(name), number_of_coconuts(number_of_coconuts) {}

    // overriden method allows for a different computation from parent/sibling
    // override is a contextual keyword (C++11 or greater) you can use to explictly
    // state a method overrides a method from the parent
    virtual double get_airspeed() override { return 42 - number_of_coconuts * load_factor; }

};
const double african_swallow::load_factor = 3;


int main(int argc, char * argv[]) {

    // abstract (has a pure virtual can't create) 
    //bird b("Polly");

    // can assign a derived (child class) to a a parent class
    bird * tweety = new european_swallow("Tweety");

    // derived classes inherit data and methods
    // methods must virtual and you must have a pointer or reference
    // to properly get the child class method called (overided the method)
    std::cout << "name: " << tweety->get_name() << '\n';
    std::cout << "name: " << tweety->get_airspeed() << '\n';

    // Collections of base class are often pointers
    // as references must be assigned on creation
    // May also use std::reference_wrapper or std::shaped_ptr
    //std::vector<bird *> birds;
    std::vector<std::reference_wrapper<bird>> birds;
    birds.push_back(*tweety);

    african_swallow sam("Sam", 2);
    birds.push_back(sam);

    //for(bird * b : birds) {
    for(bird & b : birds) {
	std::cout << b.get_name() << " " << b.get_airspeed() << '\n';
    }


    
    delete tweety;
    
    return 0;
}
