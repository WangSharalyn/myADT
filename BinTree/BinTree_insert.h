#pragma once
// ����
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(const T& e) {// ������ڵ�
	_size = 1;
	return _root = new BinNode<T>(e);
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, const T& e) {// ����x������
	_size++;
	x->insertAsLc(e);
	updateHeightAbove(x);
	return x->lc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, const T& e) { // ����x������
	_size++;
	x->insertAsRc(e);
	updateHeightAbove(x);
	return x->rc;
}