/**
 * @file file.hpp
 *
 * This is a generic C++ header template.
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 */

#ifndef INCLUDED_LIST_HPP
#define INCLUDED_LIST_HPP

template <typename type>
struct node {
    node() : data(), previous(nullptr), next(nullptr) {}
    node(const type value) : data(value), previous(nullptr), next(nullptr) {}

    type data;

    node * previous;
    node * next;

};

template <typename type>
class iterator {
private:
    node<type> * current;

public:
    iterator(node<type> * ptr) : current(ptr) {}

    // pre 
    iterator<type> & operator++() {
	if(current) {
	    current = current->next;
	}
	return *this;
    }

    // post
    iterator<type> operator++(int) {
	iterator<type> original(current);
	if(current) {
	    current = current->next;
	}
	return original;
    }

    iterator<type> & operator--() {
	if(current) {
	    current = current->previous;
	}
	return *this;
    }

    iterator<type> operator--(int) {
	iterator<type> original(current);
	if(current) {
	    current = current->previous;
	}
	return original;
    }


    type & operator*() { return current-> data;  }
    type operator*()  const { current-> data; }

    node<type> * operator->() { return current; }
    const node<type> * operator->() const { return current; };

    bool operator==(iterator<type> ptr) const { return current == ptr.current; }
    bool operator!=(iterator<type> ptr) const { return current != ptr.current; }
};


template <typename type>
class list {
private:
    node<type> * head;
    node<type> * tail;
    
public:
    list() : head(nullptr), tail(nullptr) {}
    list(const list<type>&);
    void swap(list<type> &);
    list<type> & operator=(list<type> other) { swap(other); return *this; }
    ~list();

    bool is_empty() const { return head == nullptr; }
    bool is_full() const;

    int length() const;

    type front() const { assert(!is_empty()); return head->data; }
    type &  front()    { assert(!is_empty()); return head->data; }

    type back() const { assert(!is_empty()); return tail->data; }
    type & back()     { assert(!is_empty()); return tail->data; }

    const iterator<type> begin() const { return iterator<type>(head); }
    iterator<type> begin()             { return iterator<type>(head); }

    const iterator<type> end() const { return iterator<type>(tail); }
    iterator<type> end()             { return iterator<type>(tail); }

    void insert(const type &, iterator<type>);
    void remove(iterator<type> &);
    
};

template <typename type>
list<type>::list(const list<type> & other) : list() {

    node<type> * temp = other.head;
    while(temp != nullptr) {

	if(head == nullptr) {
	    head = new node<type>(temp->data);
	    tail = head;
	} else {
	    tail->next = new node<type>(temp->data);
	    tail->next->previous = tail;
	    tail = tail->next;

	}
	
	temp = temp->next;
    }
    
}

template <typename type>
list<type>::~list() {
    while(head != nullptr) {
	node<type> * temp = head;
	head = head->next;
	delete temp;
    }
}

template <typename type>
void list<type>::swap(list<type> & other) {

    node<type> * temp_head = head;
    head = other.head;
    other.head = temp_head;

    node<type> * temp_tail = tail;
    tail = other.tail;
    other.tail = temp_tail;
    

}

template <typename type>
int list<type>::length() const {

    int result = 0;
    for(iterator<type> i = head; i != nullptr; ++i) {
	++result;
    }
    return result;
    
}

template <typename type>
bool list<type>::is_full() const {
    node<type> * temp = new(std::nothrow) node<type>();

    if(!temp) return true;

    delete temp;
    return false;
}

template <typename type>
void list<type>::insert(const type & x, iterator<type> ptr) {

    node<type> * temp = new node<type>(x);
    if(is_empty()) {
	head = temp;
	tail = temp;
    } else {

	temp->next = ptr.operator->();
	temp->previous = ptr->previous;
	if(ptr->previous != nullptr) {
	    ptr->previous->next = temp;
	} else {
	    head = temp;
	}
	ptr->previous = temp;
	
    }
    
}

template<typename type>
void list<type>::remove(iterator<type> & ptr) {
    assert(!is_empty());
    if(ptr == nullptr) return;
    
    if(ptr == head) {
	head = head->next;
    } else {
	ptr->previous->next = ptr->next;
    }

    if(ptr == tail) {
	tail = tail->previous;
    } else {
	ptr->next->previous = ptr->previous;
    }
    delete ptr.operator->();
    
}


#endif
