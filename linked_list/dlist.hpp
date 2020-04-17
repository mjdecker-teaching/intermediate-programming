#ifndef JM_DLIST_HPP_
#define JM_DLIST_HPP_

////////////////////////////////////////////////////////
//
// File:         dlist.hpp
// Description:  double linked list and iterator ADT
// Programmer:   Dr. J. Maletic, KSU
//
// Date:         11/2008
// Updated:       4/2016
//
//
//

#include <new>
#include <cassert>


/////////////////////////////////////////////////////////
// CLASS INV: (prev == 0 && next == 0) ||
//            (prev->dnode<T>() && next->dnode<T>())
// REQUIRES: assignable(T)
//
//        ------------
//        |  data    |
//        ------------
//        | <-prev   |
//        ------------
//        | next->   |
//        ------------
//
template<typename T>
class dnode {
public:
    dnode  ()           : prev(0), next(0)          {};
    dnode  (const T& x) : prev(0), next(0), data(x) {};
    dnode<T>    *prev;
    dnode<T>    *next;
    T           data;
};

///////////////////////////////////////////////////////////
// iterator for List.
// CLASS INV: current == 0 || current->dnode<T>()
// REQUIRES: assignable(T) && copyconstructable(T)
//
template <typename T>
class iterator {
public:
    iterator        (dnode<T> *ptr=0)  : current(ptr) {}
    iterator<T>&         operator++ ()                 {if (current) current = current->next; return *this; } //Pre
    iterator<T>&         operator-- ()                 {if (current) current = current->prev; return *this; } //Pre
    iterator<T>          operator++ (int)              {iterator<T> orginal(current); if (current) current = current->next; return orginal; } //Post
    iterator<T>          operator-- (int)              {iterator<T> orginal(current); if (current) current = current->prev; return orginal; } //Post
    T&              operator*  ()                 {return current->data;                                                          }
    T               operator*  () const           {return current->data;                                                          }
    dnode<T>*       operator-> ()                 {return current;                                                                }
    
    const dnode<T>* operator-> () const           {return current;                                                                }
    bool            operator== (iterator<T> ptr) const {return current == ptr.current; };
    bool            operator!= (iterator<T> ptr) const {return current != ptr.current; };

private:
    dnode<T>        *current;
};


///////////////////////////////////////////////////////////
// CLASS INV: (front_node == 0 && back_node ==0) ||
//             front_node -> X[0] <-> X[1] <-> ... <-> X[length()-1] <- back_node
//
// REQUIRES: assignable(T) && copyconstructable(T) && comparable(T) && destructable(T)
//

// first peer class, rest master/slave
template<typename T>
class list {
public:

    list        () : front_node(0), back_node(0)             {};
    list        (const list<T>&);
    list        (list<T>&&);
    void         swap        (list<T>&);
//    list<T>&     operator=   (list<T>&& rhs) {swap(rhs); return *this; };
    //list<T>&     operator=   (const list<T>&);
    list<T>&     operator=   (list<T>);
    ~list       ();

    bool         is_empty     () const        {return front_node == 0;   };
    bool         is_full      () const;
    int          length      () const;
    const iterator<T> begin       () const        {return iterator<T>(front_node);};
    const iterator<T> end         () const        {return iterator<T>(back_node);   };
    iterator<T>       begin       ()              {return iterator<T>(front_node);};
    iterator<T>       end         ()              {return iterator<T>(back_node);   };
    T            front       () const        {return front_node->data;  };
    T            back        () const        {return back_node->data;     };
    T&           front       ()              {return front_node->data;  };
    T&           back        ()              {return back_node->data;     };

    void             insertBefore(const T&, iterator<T>);
    void         insertAfter (const T&, iterator<T>);
    void                 remove      (iterator<T>&);
    //void                 remove      (iterator<T>&&);

    //really need const_iterator, but too much work.
    const iterator<T> operator[]  (int) const;      //The ith node
    iterator<T>       operator[]  (int);            //The ith node
    const iterator<T> find        (const T&) const;
    iterator<T>       find        (const T&);

private:
    dnode<T>     *front_node;      //Points to first element [0]
    dnode<T>     *back_node;         //Points to last element [length()-1].
};




///////////////////////////////////////////////////////////
// Copy constuctor.
template <typename T>
list<T>::list(const list<T> &actual) : list() {
    dnode<T> *temp = actual.front_node;
    while (temp != 0) {
        if (front_node == 0) {
            front_node = new dnode<T>(temp->data);
            back_node = front_node;
        } else {
            back_node->next = new dnode<T>(temp->data);
            back_node->next->prev = back_node;
            back_node = back_node->next;
        }
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////
// Move constuctor.
/*
template <typename T>
list<T>::list(list<T> &&actual) {
    front_node        = actual.front_node;
    back_node           = actual.back_node;
    actual.front_node = 0;
    actual.back_node    = 0;
}
*/

///////////////////////////////////////////////////////////
// Constant time swap
template <typename T>
void list<T>::swap(list<T> &b) {
    dnode<T>* temp = front_node;
    front_node      = b.front_node;
    b.front_node    = temp;
    temp           = back_node;
    back_node         = b.back_node;
    b.back_node       = temp;
}


///////////////////////////////////////////////////////////
// Destructor.
//
template <typename T>
list<T>::~list() {
    dnode<T> *temp;
    while (front_node != 0) {
        temp      = front_node;
        front_node = front_node->next;
        delete temp;
    }
}


///////////////////////////////////////////////////////////
// Assignment copy semantics
template <typename T>
list<T>& list<T>::operator=(list<T> rhs) {
    swap(rhs);
    return *this;
}

/*
template <typename T>
list<T>& list<T>::operator=(const list<T>& rhs) {
    if (front_node == rhs.front_node) return *this;
    dnode<T> *temp;
    while (front_node != 0) {
        temp      = front_node;
        front_node = front_node->next;
        delete temp;
    }
    back_node = 0;
    temp   = rhs.front_node;
    while (temp != 0) {
        if (front_node == 0) {
            front_node = new dnode<T>(temp->data);
            back_node    = front_node;
        } else {
            back_node->next       = new dnode<T>(temp->data);
            back_node->next->prev = back_node;
            back_node             = back_node->next;
        }
        temp = temp->next;
    }
    return *this;
}
*/


///////////////////////////////////////////////////////////
// ENSURES: RETVAL == true if out of memory
//
// nothrow option returns 0 if out of memory.
// Default is to throw bad_alloc
//
template <typename T>
bool list<T>::is_full() const {
    dnode<T> *temp = new(std::nothrow) dnode<T>;
    if (!temp) return true;  //No more memory to allocate
    delete temp;
    return false;
}


///////////////////////////////////////////////////////////
// ENSURES: RETVAL == number of nodes in list
//
template <typename T>
int list<T>::length() const {
    int  result = 0;
    for (iterator<T> i = front_node; i != 0; ++i) ++result;
    return result;
}


///////////////////////////////////////////////////////////
// REQUIRES: 0 <= i <= (length()-1)
// ENSURES:  RETVAL == iterator->DNODE[i] || RETVAL ==  iterator(0)
//
template <typename T>
const iterator<T> list<T>::operator[](int i) const {
    if (i < 0) return iterator<T>();
    iterator<T> result = front_node;
    int  pos = 0;
    while ((pos != i) && (result != 0)) {
        ++pos;
        ++result;
    }
    return result;
}


///////////////////////////////////////////////////////////
// REQUIRES: 0 <= i <= (length()-1)
// ENSURES:  RETVAL == iterator->DNODE[i] || RETVAL ==  iterator(0)
//
template <typename T>
iterator<T> list<T>::operator[](int i) {
    if (i < 0) return iterator<T>();
    iterator<T> result = front_node;
    int  pos = 0;
    while ((pos != i) && (result != 0)) {
        ++pos;
        ++result;
    }
    return result;
}


///////////////////////////////////////////////////////////
// ENSURES: RETVAL == iterator->(DNODE->data == x) || RETVAL == iterator(0)
//
template <typename T>
const iterator<T> list<T>::find(const T& x) const {
    for (iterator<T> i = front_node; i != 0; ++i)
        if (*i == x) return i;
    return iterator<T>();
}

///////////////////////////////////////////////////////////
// ENSURES: RETVAL == iterator->(DNODE->data == x) || RETVAL == iterator(0)
//
template <typename T>
iterator<T> list<T>::find(const T& x) {
    for (iterator<T> i = front_node; i != 0; ++i)
        if (*i == x) return i;
    return iterator<T>();
}


///////////////////////////////////////////////////////////
// REQUIRES: front_node -> a <-> b <-> ... c <- back_node
//           && ptr -> a || b || ... c
// ENSURES:  if ptr->b then front_node -> a <-> b <-> X <-> ... c <- back_node
//
template <typename T>
void list<T>::insertAfter(const T& x, iterator<T> ptr) {
    dnode<T> *temp = new dnode<T>(x);
    if (is_empty()) {
        front_node = temp;
        back_node    = temp;
    } else {
        temp->prev = ptr.operator->();
        temp->next = ptr->next;
        if (ptr->next != 0)
            ptr->next->prev = temp;
        else
            back_node = temp;
        ptr->next = temp;
    }
}

///////////////////////////////////////////////////////////
// REQUIRES: front_node -> a <-> b <-> ... c <- back_node
//           && ptr -> a || b || ... c
// ENSURES:  if ptr->b then front_node -> a <-> X <-> b <-> ... c <- back_node
//
template <typename T>
void list<T>::insertBefore(const T& x, iterator<T> ptr) {
    dnode<T> *temp = new dnode<T>(x);
    if (is_empty()) {
        front_node = temp;
        back_node    = temp;
    } else {
        temp->next = ptr.operator->();
        temp->prev = ptr->prev;
        if (ptr->prev != 0)
            ptr->prev->next = temp;
        else
            front_node = temp;
        ptr->prev = temp;
    }
}

///////////////////////////////////////////////////////////
// REQUIRES: front_node -> a <-> b <-> ... c <- back_node
//           && ptr -> a || b || ... || c
// ENSURES:  if ptr->b then front_node -> a <-> ... c <- back_node
//
// Example:
// i = l.begin();
// l.remove(i);
// assert(i == 0);
//
template <typename T>
void list<T>::remove(iterator<T> ptr) {
    assert(!is_empty());
    if (ptr == 0) return;
    if (ptr == front_node)             // Removing first node
        front_node = front_node->next;
    else
        ptr->prev->next = ptr->next; // In the middle

    if (ptr == back_node)               // Removing last node
        back_node = back_node->prev;
    else
        ptr->next->prev = ptr->prev; // In the middle
    delete ptr.operator->();
}

/*

///////////////////////////////////////////////////////////
// REQUIRES: front_node -> a <-> b <-> ... c <- back_node
//           && ptr -> a || b || ... || c
// ENSURES:  if ptr->b then front_node -> a <-> ... c <- back_node
//
// rvalue version.
// Example: l.remove(l.begin());
//
template <typename T>
void list<T>::remove(iterator<T>&& ptr) {
assert(!is_empty());
if (ptr == 0) return;
if (ptr == front_node)             // Removing first node
front_node = front_node->next;
else
ptr->prev->next = ptr->next; // In the middle

if (ptr == back_node)               // Removing last node
back_node = back_node->prev;
else
ptr->next->prev = ptr->prev; // In the middle
delete ptr.operator->();
}


*/

#endif
