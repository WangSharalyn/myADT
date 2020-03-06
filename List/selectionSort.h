#pragma once
// 对p开始的n个节点进行排序
template <typename T>
void List<T>::selectionSort(ListNodePosi(T) p, int n) {
	ListNodePosi(T) head = p->pred;
	ListNodePosi(T) tail = p;
	for (int i = 0; i < n; i++)
		tail = tail->succ;
	while (1 < n) {
		ListNodePosi(T) max = selectMax(head->succ, n);
		insertB(tail, remove(max));
		tail = tail->pred;
		n--;
	}
}