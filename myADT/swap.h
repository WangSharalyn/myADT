#pragma once
// ������������
template <typename T>
void Vector<T>::swap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}