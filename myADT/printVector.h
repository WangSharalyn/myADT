#pragma once
// ��Vector�е�Ԫ��һһ��ӡ

template <typename T>
void Vector<T>::printV() {
	for (int i = 0; i < _size; i++)
		std::cout << _elem[i] << " ";
	std::cout << std::endl;
}