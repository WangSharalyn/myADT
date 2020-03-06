#pragma once
// 在p和后继n-1个元素中选出最大值
template <typename T>
ListNodePosi(T) List<T>::selectMax(ListNodePosi(T) p, int n) {
	ListNodePosi(T) max = p;
	while (--n) {
		if (p->succ->data >= max->data)
			max = p->succ;
		p = p->succ;
	}
	return max;
}