#pragma once
template <typename T>
T PQ_complHeap<T>::getMax() {
	return element_[0];
}

template <typename T>
T PQ_complHeap<T>::delMax() {
	T x = element_[0];
	element_[0] = element_[element_.size() - 1];
	element_.remove(element_.size()-1);
	percolateDown(0, element_.size());
	return x;
}