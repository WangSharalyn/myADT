#pragma once
template <typename T>
void PQ_complHeap<T>::heapify() {
	int n = element_.size();
	for (int i = n / 2; i >= 0; --i)
		percolateDown(i, n);
}