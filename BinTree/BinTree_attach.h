#pragma once
// ������һ����T��Ϊ�µ�����
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>*& T) {// ��Ϊ������
	_size += T->_size;
	if (x->lc = T->_root)
		x->lc->parent = x;
	updateHeightAbove(x);
	T->_root = nullptr;
	T->_size = 0;
	T = nullptr;
	return x;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>*& T) {// ��Ϊ������
	_size += T->_size;
	if (x->rc = T->_root)
		x->rc->parent = x;
	updateHeightAbove(x);
	T->_root = nullptr;
	T->_size = 0;
	T = nullptr;
	return x;
}