/**
 * @file queue_linked_list_.hpp
 *
 * Queue ADT via a node class.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#ifndef INCLUDED_QUEUE_HPP
#define INCLUDED_QUEUE_HPP

#include <cassert>

template<typename type>
struct node {
    type data;
    node * next;

    node() : next(nullptr) {}
    node(const type & item, node * link = nullptr) : data(item), next(link) {}
};

template<typename type>
class queue {
private:
    node<type> * head;
    node<type> * tail;

public:
    queue() : head(nullptr), tail(nullptr) {}
    queue(const queue &);
    ~queue();
    void swap(queue &);
    queue<type> & operator=(queue<type> rhs) { swap(rhs); return *this; }


    type front() const;
    type & front();

    type back() const;
    type & back();

    void dequeue();
    void enqueue(const type & item);

    bool is_empty() const {  return head == nullptr; }
    bool is_full() const;

};

template<typename type>
queue<type>::~queue() {
    while(!is_empty()) {
	dequeue();
    }

}

template<typename type>
queue<type>::queue(const queue<type> & that) {

    for(node<type> * temp = that->head; temp != nullptr; temp = temp->next) {
	enqueue(temp->data);
/*
	if(head == nullptr) {
	    head = new node<type>(temp->data);
	    tail = tail;
	} else {
	    tail->next = new node<type>(temp->data);
	    tail = tail->next;
	}
*/
    }

}


template<typename type>
void queue<type>::swap(queue<type> & rhs) {
    node<type> * temp_head = head;
    head = rhs.head;
    rhs.head = temp_head;

    node<type> * temp_tail = tail;
    tail = rhs.tail;
    rhs.tail = temp_tail;

}

template<typename type>
void queue<type>::enqueue(const type & item) {
    assert(!is_full());

    node<type> * new_node = new node<type>(item);

    if(tail == nullptr) {
	head = new_node;
    } else {
	tail->next = new_node;
    }

    tail = new_node;
    
}

template<typename type>
void queue<type>::dequeue() {
    assert(!is_empty());

    node<type> * temp = head;
    head = head->next;
    delete temp;
    
}

template<typename type>
type queue<type>::front() const {
    assert(!is_empty());
    return head->data;
}

template<typename type>
type & queue<type>::front() {
    assert(!is_empty());
    return head->data;
}

template<typename type>
type queue<type>::back() const {
    assert(!is_empty());
    return tail->data;
}

template<typename type>
type & queue<type>::back() {
    assert(!is_empty());
    return tail->data;
}

template<typename type>
bool queue<type>::is_full() const {

    node<type> * temp = new (std::nothrow) node<type>;
    if(!temp) return true;

    delete temp;
    return false;

}

#endif
