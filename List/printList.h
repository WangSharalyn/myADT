#pragma once
#include <iostream>

// 打印List中各节点数据
template <typename T>
void List<T>::printL() {
	ListNodePosi(T) curr = header->succ;
	while (curr != trailer) {
		std::cout << curr->data << " ";
		curr = curr->succ;
	}
	std::cout << std::endl;
}