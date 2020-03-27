#ifndef CS2_ARRAY_HPP
#define CS2_ARRAY_HPP

#include <iostream>
#include <cassert>

template <typename type>
class darray {

private:
    type * data;
    int cap;

    darray(int new_cap, const darray<type> & rhs);

public:

    // constructors
    darray() : data(nullptr), cap(0) {}
    darray(int);
    darray(const darray<type> & rhs);
    
    // destructor
    ~darray();

    // swap
    void swap(darray<type> & rhs);
    // assignment
    darray<type> & operator=(darray<type> rhs);

    // subscript
    type operator[](int) const;
    type & operator[](int);

    // capacity()
    int capacity() const;

    // reset capacity
    void reset_capacity(int new_cap);

};

template<typename type>
darray<type>::darray(int new_cap) : cap(new_cap) {
    data = new type[new_cap];
}

template<typename type>
darray<type>::~darray() {
    delete [] data;
}

template<typename type>
darray<type>::darray(const darray<type> & rhs) : darray(rhs.cap) {
    for(int i = 0; i < cap; ++i) {
	data[i] = rhs.data[i];
    }
}


template<typename type>
darray<type>::darray(int new_cap, const darray<type> & rhs) : darray(new_cap) {

    int smaller = new_cap;
    if(rhs.cap < smaller) {
	smaller = rhs.cap;
    }

    for(int i = 0; i < smaller; ++i) {
	data[i] = rhs.data[i];
    }
    
    int i = smaller;
    while(i < new_cap) {
	data[i++] = 0;
    }

}

template<typename type>
void darray<type>::swap(darray<type> & rhs) {

    int temp_cap = cap;
    cap = rhs.cap;
    rhs.cap = temp_cap;

    type * temp_data = data;
    data = rhs.data;
    rhs.data = temp_data;

}

template<typename type>
darray<type> & darray<type>::operator=(darray<type> rhs) {
    swap(rhs);
    return *this;
}

template<typename type>
type darray<type>::operator[](int i) const {
    assert(i >= 0 && i < cap);
    return data[i];
}

template<typename type>
type & darray<type>::operator[](int i) {
    assert(i >= 0 && i < cap);
    return data[i];
}

template<typename type>
int darray<type>::capacity() const {
    return cap;
}

template<typename type>
void darray<type>::reset_capacity(int new_cap) {
    darray<type> temp(new_cap, *this);
    swap(temp);

/*    int * temp_data = new int[new_cap];
    for(int i = 0; i < new_cap; ++i) {
	if(i >= cap) {
	    temp_data[i] = 0;
	} else {
	    temp_data[i] = data[i];
	}
    }

    delete [] data;
    data = temp_data;
    cap = new_cap;
*/
}

template<typename type>
std::ostream & operator<<(std::ostream & out, const darray<type> & ar) {
    for(int i = 0; i < ar.capacity(); ++i) {
	out << ar[i] << " ";
    }
    return out;
}

template<typename type>
std::istream & operator>>(std::istream & in, darray<type> & ar) {

    for(int i = 0; i < ar.capacity(); ++i) {
	in >> ar[i];
    }

    return in;
}

#endif

