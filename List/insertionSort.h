#pragma once
// ≤Â»Î≈≈–Ú
template <typename T>
void List<T>::insertionSort(ListNodePosi(T) p, int n) {
	ListNodePosi(T) head = p->pred;
	ListNodePosi(T) tail = p;
	p = p->succ;
	for (int i = 1; i < n; i++) {
		while (tail != head && tail->data > p->data)
			tail = tail->pred;
		ListNodePosi(T) curr = p;
		p = p->succ;
		insertA(tail, remove(curr));
		tail = p->pred;
	}
}