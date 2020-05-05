#pragma once
#include "../List/List.h"
// ʹ���б�˫������ʵ��ջ
template <typename T> class Stack : public List<T> {
public:
	void push(const T& e) {
		this->insertAsLast(e);
	}

	T pop() {
		return this->remove(this->last());
	}

	T top() {
		return this->last()->data;
	}
	bool empty() {
		return this->size() == 0;
	}
};