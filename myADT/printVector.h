#pragma once
// 将Vector中的元素一一打印

template <typename T>
void Vector<T>::printV() {
	for (int i = 0; i < _size; i++)
		std::cout << _elem[i] << " ";
	std::cout << std::endl;
}