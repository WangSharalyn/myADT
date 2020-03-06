#pragma once
// 从p开始拷贝n项
template <typename T>
void List<T>::copyNodes(ListNodePosi(T) p, int n) {
	init();
	while (n--) {
		insertAsLast(p->data);
		p = p->succ;
	}
}