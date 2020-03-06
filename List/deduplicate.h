#pragma once
// 无序列表去重
template <typename T>
int List<T>::deduplicate() {
	int oldSize = _size;
	ListNodePosi(T) p = first()->succ;
	for (int i = 1; i < oldSize; i++) {
		ListNodePosi(T) temp = find(p->data, i, p);
		if (temp)
			remove(temp);
		p = p->succ;
	}
	return oldSize - _size;
}