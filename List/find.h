#pragma once
// �����б����
template <typename T>
ListNodePosi(T) List<T>::find(const T& e, int n, ListNodePosi(T) p) const {
	p = p->pred;
	while (n--) {
		if (e == p->data)
			return p;
		else
			p = p->pred;
	}
	return nullptr;
}