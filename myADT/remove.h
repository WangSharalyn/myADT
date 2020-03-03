#pragma once

template <typename T>
int Vector<T>::remove(Rank lo, Rank hi) { // assert(0<=lo<=hi<_size)
	while (hi < _size) {_elem[lo++] = _elem[hi++];}
	_size = lo;
	return hi - lo;
}

template <typename T>
T Vector<T>::remove(Rank r) {
	T v = _elem[r];
	remove(r, r + 1);
	return v;
}
