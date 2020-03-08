#pragma once
#include "../List/List.h"
// vector实现队列
template <typename T> class Queue : public List<T> {
public:
	void enqueue(const T& e) {
		this->insertAsLast(e);
	}
	T dequeue() {
		return this->remove(this->first());
	}
};