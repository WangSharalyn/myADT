#pragma once
// ���������Ĺ�ģ
template <typename T>
int BinTree<T>::size(BinNodePosi(T) x) {
	return x ? x->size() : 0;
}