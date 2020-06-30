#pragma once

template <typename T>
Rank PQ_complHeap<T>::percolateDown(Rank i, Rank n) {
	int parent, child;
	for (parent = i; (parent * 2 + 1) < n; parent = child) {
		child = parent * 2 + 1;
		if ((child + 1 < n) && (element_[child] < element_[child + 1]))
			child++;
		if (element_[parent] < element_[child])
			std::swap(element_[parent], element_[child]);
		else
			break;
	}
	return parent;
}