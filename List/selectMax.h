#pragma once
// ��p�ͺ��n-1��Ԫ����ѡ�����ֵ
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