#pragma once
// �����б����򣬷��ز�����e�������
template <typename T>
ListNodePosi(T) List<T>::search(const T& e, int n, ListNodePosi(T) p) const {
	p = p->pred;
	while (n-- && e < p->data)
		p = p->pred;
	return p;
}