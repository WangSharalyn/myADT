#pragma once
// 返回子树的规模
template <typename T>
int BinTree<T>::size(BinNodePosi(T) x) {
	return x ? x->size() : 0;
}