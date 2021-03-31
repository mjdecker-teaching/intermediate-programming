
#ifndef INCLUDED_DLIST_HPP
#define INCLUDED_DLIST_HPP

////////////////////////////////////////////////////////
//
// File:         dlist.hpp
// Description:  double linked list and iterator ADT
// Programmers:   Dr. J. Maletic, KSU, Dr. M. Decker, BGSU
//
// Date:         11/2008
// Updated:       4/2020
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
    iterator        (dnode<T> * ptr=0)  : current(ptr) {}
    iterator<T> &        operator++ ()                 {if (current) current = current->next; return *this; } //Pre
    iterator<T> &        operator-- ()                 {if (current) current = current->prev; return *this; } //Pre
    iterator<T>          operator++ (int)              {iterator<T> orginal(current); if (current) current = current->next; return orginal; } //Post
    iterator<T>          operator-- (int)              {iterator<T> orginal(current); if (current) current = current->prev; return orginal; } //Post
    T &             operator*  ()                 {return current->data;                                                          }
    T               operator*  () const           {return current->data;                                                          }
    dnode<T> *      operator-> ()                 {return current;                                                                }
    
    const dnode<T> * operator-> () const           {return current;                                                                }
    bool             operator== (iterator<T> ptr) const {return current == ptr.current; };
    bool             operator!= (iterator<T> ptr) const {return current != ptr.current; };

private:
    dnode<T> *        current;
};


///////////////////////////////////////////////////////////
// CLASS INV: (head == 0 && tail ==0) ||
//             head -> X[0] <-> X[1] <-> ... <-> X[length()-1] <- tail
//
// REQUIRES: assignable(T) && copyconstructable(T) && comparable(T) && destructable(T)
//

// first peer class, rest master/slave
template<typename T>
class list {
public:

    list        () : head(nullptr), tail(nullptr)             {};
    list        (const list<T> &);
    //list        (list<T> &&);
    void         swap        (list<T> &);
    list<T>&     operator=   (list<T> & rhs) { swap(rhs); return *this; };
    //list<T>&     operator=   (list<T>&& rhs) { swap(rhs); return *this; };
    //list<T>&     operator=   (const list<T>&);
    list<T>&     operator=   (list<T>);
    ~list       ();

    bool         is_empty     () const        {return head == 0; };
    bool         is_full      () const;
    int          length       () const;
    const iterator<T> begin       () const        {return iterator<T>(head); };
    const iterator<T> end         () const        {return iterator<T>(tail); };
    iterator<T>       begin       ()              {return iterator<T>(head); };
    iterator<T>       end         ()              {return iterator<T>(tail); };
    T            front       () const        {return head->data;  };
    T            back        () const        {return tail->data;  };
    T &          front       ()              {return head->data;  };
    T &          back        ()              {return tail->data;  };

    void         insertBefore(const T &, iterator<T>);
    void         insertAfter (const T &, iterator<T>);
    void         remove      (iterator<T> &);
    //void                 remove      (iterator<T>&&);

    // really need const_iterator, but too much work.
    const iterator<T> operator[]  (int) const;      //The ith node
    iterator<T>       operator[]  (int);            //The ith node
    const iterator<T> find        (const T &) const;
    iterator<T>       find        (const T &);

private:
    dnode<T> *    head;      //Points to first element [0]
    dnode<T> *    tail;      //Points to last element [length()-1].
};




///////////////////////////////////////////////////////////
// Copy constuctor.
template <typename T>
list<T>::list(const list<T> &actual) : list() {
    dnode<T> * temp = actual.head;
    while (temp != 0) {
        if (head == 0) {
            head = new dnode<T>(temp->data);
            tail = head;
        } else {
            tail->next = new dnode<T>(temp->data);
            tail->next->prev = tail;
            tail = tail->next;
        }
        temp = temp->next;
    }
}

///////////////////////////////////////////////////////////
// Move constuctor.
/*
template <typename T>
list<T>::list(list<T> &&actual) {
    head        = actual.head;
    tail           = actual.tail;
    actual.head = 0;
    actual.tail    = 0;
}
*/

///////////////////////////////////////////////////////////
// Constant time swap
template <typename T>
void list<T>::swap(list<T> &b) {
    dnode<T> * temp = head;
    head            = b.head;
    b.head          = temp;
    temp            = tail;
    tail            = b.tail;
    b.tail          = temp;
}


///////////////////////////////////////////////////////////
// Destructor.
//
template <typename T>
list<T>::~list() {
    dnode<T> * temp;
    while (head != 0) {
        temp      = head;
        head = head->next;
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
    if (head == rhs.head) return *this;
    dnode<T> *temp;
    while (head != 0) {
        temp      = head;
        head = head->next;
        delete temp;
    }
    tail = 0;
    temp   = rhs.head;
    while (temp != 0) {
        if (head == 0) {
            head = new dnode<T>(temp->data);
            tail    = head;
        } else {
            tail->next       = new dnode<T>(temp->data);
            tail->next->prev = tail;
            tail             = tail->next;
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
    dnode<T> * temp = new(std::nothrow) dnode<T>;
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
    for (iterator<T> i = head; i != 0; ++i) ++result;
    return result;
}


///////////////////////////////////////////////////////////
// REQUIRES: 0 <= i <= (length()-1)
// ENSURES:  RETVAL == iterator->DNODE[i] || RETVAL ==  iterator(0)
//
template <typename T>
const iterator<T> list<T>::operator[](int i) const {
    if (i < 0) return iterator<T>();
    iterator<T> result = head;
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
    iterator<T> result = head;
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
    for (iterator<T> i = head; i != 0; ++i)
        if (*i == x) return i;
    return iterator<T>();
}

///////////////////////////////////////////////////////////
// ENSURES: RETVAL == iterator->(DNODE->data == x) || RETVAL == iterator(0)
//
template <typename T>
iterator<T> list<T>::find(const T& x) {
    for (iterator<T> i = head; i != 0; ++i)
        if (*i == x) return i;
    return iterator<T>();
}


///////////////////////////////////////////////////////////
// REQUIRES: head -> a <-> b <-> ... c <- tail
//           && ptr -> a || b || ... c
// ENSURES:  if ptr->b then head -> a <-> b <-> X <-> ... c <- tail
//
template <typename T>
void list<T>::insertAfter(const T& x, iterator<T> ptr) {
    dnode<T> * temp = new dnode<T>(x);
    if (is_empty()) {
        head = temp;
        tail    = temp;
    } else {
        temp->prev = ptr.operator->();
        temp->next = ptr->next;
        if (ptr->next != 0)
            ptr->next->prev = temp;
        else
            tail = temp;
        ptr->next = temp;
    }
}

///////////////////////////////////////////////////////////
// REQUIRES: head -> a <-> b <-> ... c <- tail
//           && ptr -> a || b || ... c
// ENSURES:  if ptr->b then head -> a <-> X <-> b <-> ... c <- tail
//
template <typename T>
void list<T>::insertBefore(const T& x, iterator<T> ptr) {
    dnode<T> *temp = new dnode<T>(x);
    if (is_empty()) {
        head = temp;
        tail    = temp;
    } else {
        temp->next = ptr.operator->();
        temp->prev = ptr->prev;
        if (ptr->prev != 0)
            ptr->prev->next = temp;
        else
            head = temp;
        ptr->prev = temp;
    }
}

///////////////////////////////////////////////////////////
// REQUIRES: head -> a <-> b <-> ... c <- tail
//           && ptr -> a || b || ... || c
// ENSURES:  if ptr->b then head -> a <-> ... c <- tail
//
// Example:
// i = l.begin();
// l.remove(i);
// assert(i == 0);
//
template <typename T>
void list<T>::remove(iterator<T> & ptr) {
    assert(!is_empty());
    if (ptr == 0) return;
    if (ptr == head)             // Removing first node
        head = head->next;
    else
        ptr->prev->next = ptr->next; // In the middle

    if (ptr == tail)               // Removing last node
        tail = tail->prev;
    else
        ptr->next->prev = ptr->prev; // In the middle
    delete ptr.operator->();
}

/*

///////////////////////////////////////////////////////////
// REQUIRES: head -> a <-> b <-> ... c <- tail
//           && ptr -> a || b || ... || c
// ENSURES:  if ptr->b then head -> a <-> ... c <- tail
//
// rvalue version.
// Example: l.remove(l.begin());
//
template <typename T>
void list<T>::remove(iterator<T>&& ptr) {
assert(!is_empty());
if (ptr == 0) return;
if (ptr == head)             // Removing first node
head = head->next;
else
ptr->prev->next = ptr->next; // In the middle

if (ptr == tail)               // Removing last node
tail = tail->prev;
else
ptr->next->prev = ptr->prev; // In the middle
delete ptr.operator->();
}


*/

#endif
