#pragma once
// ²åÈëÔªËØ
template <typename T>
Rank Vector<T>::insert(const T& e, Rank r) {
	Rank hi = _size;
	while (r < hi) {
		_elem[hi] = _elem[hi - 1];
		hi--;
	}
	_elem[r] = e;
	_size++;
	return r;
}