#pragma once
#include <iostream>

// ��ӡList�и��ڵ�����
template <typename T>
void List<T>::printL() {
	ListNodePosi(T) curr = header->succ;
	while (curr != trailer) {
		std::cout << curr->data << " ";
		curr = curr->succ;
	}
	std::cout << std::endl;
}