#pragma once
#include "../myADT/Vector.h"

// Stack����
template <typename T> class Stack :public Vector<T> {
public:
	T pop();//����
	T top(); // ����Ԫ�ط���
	void push(const T& e); // ѹջ
};

template <typename T>
T Stack<T>::pop() {
	return this->remove(this->size() - 1);
}

template <typename T>
T Stack<T>::top() {
	return (*this)[this->size()-1];
}

template <typename T>
void Stack<T>::push(const T& e) {
	this->insert(e);
}