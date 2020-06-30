#pragma once

template <typename T>
Rank PQ_complHeap<T>::percolateUp(Rank i) {
	int parent = (i - 1) / 2;
	while (parent >= 0) {
		if (element_[parent] < element_[i])
			std::swap(element_[parent], element_[i]);
		else
			break;
		i = parent;
		parent = (i - 1) / 2;
	}
	return i;
}