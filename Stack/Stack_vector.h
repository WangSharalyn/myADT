#pragma once
#include "../myADT/Vector.h"

// Stack队列
template <typename T> class Stack :public Vector<T> {
public:
	T pop();//弹出
	T top(); // 顶部元素访问
	void push(const T& e); // 压栈
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