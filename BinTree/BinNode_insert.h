#pragma once
template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLC(const T& e) {
	lc = new BinNode(e, this);
	return lc;
}

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRC(const T& e) {
	return rc = new BinNode(e, this);
}