#pragma once

template <typename T>
static int removeAt(BinNodePosi(T) x) {
	if (!x) return 0;
	int n = 1 + removeAt(x->lc) + removeAt(x->rc);
	delete x;
	return n;
}

template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x) {
	if (!x->parent) _root = nullptr;
	else if (x->parent->lc == x) x->parent->lc = nullptr;
	else x->parent->rc = nullptr;
	updateHightAbove(x->parent);
	int n = removeAt(x);
	_size -= n;
	return n;
}