#include "PQ_complHeap.h"

int main() {
	int arr[] = { 3, 7, 8, 2};
	PQ_complHeap<int> pq(arr, 4);
	pq.print();
	pq.delMax();
	pq.print();
	PQ_complHeap<int> pq2;
	pq2.insert(3);
	pq2.insert(7);
	pq2.insert(8);
	pq2.insert(2);
	pq2.print();
	pq2.delMax();
	pq2.print();
	return 0;
}