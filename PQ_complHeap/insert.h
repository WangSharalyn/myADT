#pragma once
template <typename T>
void PQ_complHeap<T>::insert(T x) {
	element_.insert(x);
	percolateUp(element_.size() - 1);
}