#pragma once
#include "../List/List.h"
// vectorʵ�ֶ���
template <typename T> class Queue : public List<T> {
public:
	void enqueue(const T& e) {
		this->insertAsLast(e);
	}
	T dequeue() {
		return this->remove(this->first());
	}
};