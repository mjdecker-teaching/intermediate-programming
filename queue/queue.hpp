#ifndef CS2_QUEUE_HPP
#define CS2_QUEUE_HPP

#include <cassert>

const int MAX_SIZE = 4;

template<typename type>
class queue {
private:
    int start_pos;
    int end_pos;
    int size;

    type buffer[MAX_SIZE];

public:

    queue() : start_pos(0), end_pos(-1), size(0) {}

    void enqueue(const type & item) {
	assert(!full());
	++size;
	++end_pos;
	end_pos %= MAX_SIZE;
	buffer[end_pos] = item;
    }

    void dequeue() {
	assert(!empty());
	--size;
	++start_pos;
	start_pos %= MAX_SIZE;
    }
    
    type front() const {
	assert(!empty());
	return buffer[start_pos];
    }

    type & front() {
	assert(!empty());
	return buffer[start_pos];
    }

    type back() const {
	assert(!empty());
	return buffer[end_pos];
    }

    type & back() {
	assert(!empty());
	return buffer[end_pos];
    }

    bool is_full() const {
	return size == MAX_SIZE;
    }
    bool is_empty() const {
	return size == 0;
    }

};

#endif
