#ifndef DSTACK_HPP
#define DSTACK_HPP

#include <cassert>
#include <new>

template<typename type>
struct node {
    node() : next(nullptr) {}
    node(const type & x) : data(x), next(nullptr) {}

    type data;
    node<type> * next;
};

template <typename type>
class stack {
public:
    stack() : tos(nullptr) {}
    stack(const stack<type> &);
    ~stack();

    void swap (stack<type>&);
    stack<type> & operator=(stack<type>);

    bool empty() const  { return tos == nullptr; }
    bool full() const;

    type & top();
    type top() const;

    void pop();


    void push(const type&);

private:
    node<type>   *tos;
};

template<typename type>
void stack<type>::swap(stack<type> & actual) {

    node<type> * temp_tos = tos;
    tos = actual.tos;
    actual.tos = temp_tos;

} 

template<typename type>
stack<type> & stack<type>::operator=(stack<type> rhs) {
    swap(rhs);
    return *this;
}

template <typename type>
stack<type>::stack(const stack<type>& actual) {
    node<type> * bottom;
    node<type> * temp   = actual.tos;
    tos = nullptr;
    while (temp != nullptr) {

        if (tos == nullptr) {
            tos = new node<type>(temp->data);
            bottom = tos;
        }
        else {
            bottom->next = new node<type>(temp->data);
            bottom = bottom->next;
        }
        temp   = temp->next;
    }
}

template <typename type>
stack<type>::~stack() {
    node<type> * temp;
    while (tos != 0) {
        temp = tos;
        tos  = tos->next;
        delete temp;
    }
}

template <typename type>
bool stack<type>::full() const {

    node<type> * temp = new (std::nothrow) node<type>;
    if (!temp)  return true;

    delete temp;
    return false;
}

template <typename type>
type stack<type>::top() const {
    assert(!empty());
    return tos->data;
}

template <typename type>
type & stack<type>::top() {
    assert(!empty());
    return tos->data;
}

template <typename type>
void stack<type>::pop() {
    assert(!empty());

    type result = tos->data;
    node<type> * temp = tos;
    tos = tos->next;
    delete temp;
}

template <typename type>
void stack<type>::push(const type & newItem) {
    assert(!full());
    node<type> * temp = new node<type>(newItem);
    temp->next = tos;
    tos = temp;
}

#endif
