/**
 * @file iterators.cpp
 *
 * Illustrates a few iterators concepts (used on a vector)
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#include <iostream>
#include <vector>
#include <string>

int main(int argc, char * argv[]) {

    // Declare a vector with two words
    std::vector<std::string> words { "Hello",  "World" };

    // Iterators behave like pointers and are used to
    // traverse and access a container

    // Get an iterator pointing to first element via begin()
    // Type of iterators is always full container type (e.g., std::vector<std::string>) + ::iterator
    std::vector<std::string>::iterator itr = words.begin();

    // Dereference (*) to access stored item
    std::cout << "*itr: " << *itr << '\n';

    // Can also access a member if object with ->
    std::cout << "itr->size(): " << itr->size() << '\n';


    // Increment or decrement to move iterator and traverse container
    // points to second element after this
    ++itr;
    std::cout << '\n';
    std::cout << "++itr;\n";
    std::cout << "*itr: " << *itr << '\n';
    
    // Supports comparison minimally == and !=
    // end() gets an iterator just past end of list
    std::cout << '\n';
    std::cout << "itr != words.end(): " << std::boolalpha <<  (itr != words.end()) << '\n';

    // Now points past last element (i.e., end) and has no valid element
    ++itr;
    std::cout << "++itr;\n";
    std::cout << "itr == words.end(): " << std::boolalpha << (itr != words.end()) << '\n';


    // Move to last element
    --itr;

    // insert() puts an element just before iterator
    words.insert(itr, "Hi");


    std::cout << '\n';

    // Use iterators in a loop from begin() up until end() to traverse entire container
    // Some Visual Studio instances might ask for typename before iterator type declaration
    for(std::vector<std::string>::iterator pos = words.begin(); pos != words.end(); ++pos) {
	std::cout << *pos << ' ';
    }
    std::cout << "\n\n";

    // move iterator to begining (or just get a new one pointing to begining)
    --itr;
    --itr;

    // remove() deletes an element from container
    // An iterator pointing to that element is invalidated and can't be used
    words.erase(itr);

    // itr can not be used now, we could if we did either of these

    // post means it is a temp (itr already moved)
    //words.erase(itr++); 

    // Use a temporary
    //std::vector<std::string>::iterator temp_itr = itr;
    //++itr;
    //words.erase(temp_itr);
        
    // Ranged-based for uses iterators underneath
    for(const std::string & word : words) {
	std::cout << word << ' ';
    }
    std::cout << '\n';

    return 0;
}
