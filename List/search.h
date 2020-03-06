#pragma once
// 有序列表排序，返回不大于e的最大秩
template <typename T>
ListNodePosi(T) List<T>::search(const T& e, int n, ListNodePosi(T) p) const {
	p = p->pred;
	while (n-- && e < p->data)
		p = p->pred;
	return p;
}