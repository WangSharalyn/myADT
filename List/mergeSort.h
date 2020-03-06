#pragma once
// πÈ≤¢≈≈–Ú
template <typename T>
void List<T>::mergeSort(ListNodePosi(T) p, int n) {
	if (n < 2) return;
	int mi = n >> 1;
	ListNodePosi(T) q = p;
	for (int i = 0; i < mi; i++) q = q->succ;
	mergeSort(p, mi);
	mergeSort(q, n - mi);
}