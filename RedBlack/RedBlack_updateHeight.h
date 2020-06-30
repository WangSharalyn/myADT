#pragma once
template <typename T>
int RedBlack<T>::updateHeight(BinNodePosi(T) x) {// 高度为黑高度
	x->height = __max(stature(x->lc), stature(x->rc)); // 孩子的黑高度一般相等，除非出现双黑
	return IsBlack(x) ? x->height++; x->height;
}