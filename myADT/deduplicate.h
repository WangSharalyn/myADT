#pragma once

// 无序向量去重
template <typename T>
int Vector<T>::deduplicate() {
	int oldSize = _size;
	Rank i = 1;
	while (i < _size)
		find(_elem[i], 0, i) ? i++ : remove(i);
	return oldSize - _size;
}