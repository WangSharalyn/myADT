#pragma once
// ���������[]��ѭ�ȷ���
template <typename T>
T& List<T>::operator[](Rank r) {
	ListNodePosi(T) curr = first();
	while (0 < r--)
		curr = curr->succ;
	return curr->data;
}