/**
 * @file set.cpp
 *
 * Implementation of set class
 *
 * @author Michael John Decker, Ph.D. <mdecke@bgsu.edu>
 * @date 2/17/2020
 */

#include "set.hpp"

bool in_universe(int number) {
    if(number < 0) return false;
    if(number >= MAX) return false;

    return true;

}

// default ctor
set::set() {

    for(int i = 0; i < MAX; ++i) {
	in_set[i] = false;
    }

}


set::set(int num) : set() {
    if(!in_universe(num)) return;

    in_set[num] = true;

}

set::set(std::initializer_list<int> init_list) : set() {

    for(int i : init_list) {
	if(in_universe(i)) {
	    in_set[i] = true;
	}
    }
}

bool set::operator==(const set & that) const {
    for(int i = 0; i < MAX; ++i) {
	if(this->in_set[i] != that.in_set[i]) return false;
    }

    return true;
}

std::ostream & operator<<(std::ostream & out,
                          const set & aset) {
    out << "{";

    bool output_comma = false;
    for(int i = 0; i < MAX; i++) {
	if(aset.in_set[i]) {
	    if(output_comma) {
		out << ", ";
	    }
	    out << i;
	    output_comma = true;
	}
    }

    out << "}";
    
    return out;
}
