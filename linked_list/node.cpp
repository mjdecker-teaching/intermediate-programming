/**
 *  @file node.cpp
 *
 *  This is a generic C++ main file.
 *
 *  @author Michael John Decker <mdecker6@kent.edu>
 */

#include <iostream>
#include <string>
template<typename type>
struct node {
    node() : data(), next(nullptr) {}
    node(const type & value) : data(value), next(nullptr) {}
    type data;
    node<type> * next;
};

int main() {

    node<int> * node_one = new node<int>(1);

    node<int> * node_two = new node<int>(2);
    node_one->next = node_two;

    node<int> * node_three = new node<int>(4);
    node_two->next = node_three;

    //std::cerr << node_one->next->next->data << '\n';

    node<int> * node_four = new node<int>(8);

    node_four->next = node_one->next;
    node_one->next = node_four;

    //std::cerr << node_one->next->data << '\n';
    //std::cerr << node_one->next->next->data << '\n';

    //node * temp_node = node_one->next->next;
    //node_one->next->next = node_one->next->next->next;
    //delete temp_node;

    //std::cerr << node_one->next->data << '\n';
    //std::cerr << node_one->next->next->data << '\n';

    int pos = 0;
    for(node<int> * temp = node_one; temp != nullptr; temp = temp->next) {
	std::cout << "pos: " << pos << " data: " << temp->data << '\n';
	++pos;
    }

    node<int> * temp = node_one;
    while(temp != nullptr) {
	node<int> * save_ptr = temp->next;
	delete temp;
	temp = save_ptr;
    }

    node<std::string> foo;
    foo.data = "hello world";
    std::cerr << foo.data << '\n';

    return 0;
}
