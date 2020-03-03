#pragma once
// 有序向量唯一化
template <typename T>
int Vector<T>::uniquify() {
	Rank i = 0, j = 0;
	while (++j < _size) {
		if (_elem[j] != _elem[i])
			_elem[++i] = _elem[j];
		_size = ++i;
	}
	return j - i;
}