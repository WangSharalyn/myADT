#pragma once
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(const T& e) {
	_size = 1;
	return _root = new BinNode<T>(e);
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, const T& e) {
	_size++;
	x->insertAsLC(e);
	updateHightAbove(x);
	return x->lc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, const T& e) {
	_size++;
	x->insertAsRC(e);
	updateHightAbove(x);
	return x->rc;
}