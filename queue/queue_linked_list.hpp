#ifndef DQUEUE_HPP_
#define DQUEUE_HPP_

#include <cassert>
#include <new>

template <typename type>
struct node {
    node() : next(nullptr) {}
    node(const type & item) : next(nullptr), data(item) {}

    node<type> * next;
    type data;
};

template <typename type>
class queue {
private:
    node<type> * start;
    node<type> * end;
public:

    queue() : start(nullptr), end(nullptr) {};
    ~queue();

    queue(queue<type>&);
    void swap(queue<type> &);
    queue<type> & operator=(queue<type> rhs) { swap(rhs); return *this; }
    
    type front() const;
    type & front();

    type back() const;
    type & back();

    void dequeue();
    void enqueue(const type &);
    bool empty() const { return start == 0; };
    bool full() const;

};

template <typename type>
queue<type>::~queue() {
    while(!empty())
	dequeue();
    
/*    while (start != 0) {
        node<type> * temp = start;
        start = start->next;
        delete temp;
    }
*/
}

template <typename type>
queue<type>::queue(queue<type>& actual) : queue<type>() {
    node<type> * temp = actual.start;

    for(node<type> temp = actual.start; temp != nullptr; temp = temp->next) {
	enqueue(temp->data);
/*
        if (start == nullptr) {
            start = new node<type>(temp->data);
            end = start;
        } else {
            end->next = new node<type>(temp->data);
            end = end->next;
        }
    }
*/
}


//////////////////////////////////////////////////////////
// Constant time swap
//
template <typename type>
void queue<type>::swap(queue<type>& x) {
    node<type> * temp_start = start;
    start = x.start;
    x.start = temp_start;

    node<type> * temp_end = end;
    end = x.end;
    x.end = temp_end;
}


template <typename type>
bool queue<type>::full() const {
    node<type> * temp = new (std::nothrow) node<type>;
    if (!temp) return true;

    delete temp;
    return false;
}

template<typename type>
type queue<type>::front() const {
    assert(!empty());
    return start->data;
}

template<typename type>
type & queue<type>::front() {
    assert(!empty());
    return start->data;
}

template<typename type>
type queue<type>::back() const {
    assert(!empty());
    return end->data;
}

template<typename type>
type & queue<type>::back() {
    assert(!empty());
    return end->data;
}

template <typename type>
void queue<type>::dequeue() {
    assert(!empty());

    type result = start->data;
    node<type> *temp = start;
    start = start->next;
    delete temp;
}

template <typename type>
void queue<type>::enqueue(const type & item) {
    assert(!full());

    node<type> * temp = new node<type>(item);
    if (end == nullptr)
        start = temp;
    else
        end->next = temp;
    end = temp;
}

#endif
