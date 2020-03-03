#pragma once
// 交换两个数字
template <typename T>
void Vector<T>::swap(T& a, T& b) {
	T temp;
	temp = a;
	a = b;
	b = temp;
}