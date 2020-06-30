#pragma once
#include "../myADT/Vector.h"

template <typename T> class PQ_complHeap {
public:
	PQ_complHeap() = default;
	PQ_complHeap(T* A, int n) {
		while (n--) {
			element_.insert(*A);
			++A;
		}
		heapify();
	}

	void insert(T);
	T getMax();
	T delMax();
	void print() {
		element_.printV();
	}
private:
	Vector<T> element_;

	Rank percolateDown(Rank i, Rank n); // оббк
	Rank percolateUp(Rank i); // иобк
	void heapify();
};

#include "percolateDown.h"
#include "percolateUp.h"
#include "heapify.h"
#include "insert.h"
#include "max.h"