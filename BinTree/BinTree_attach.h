#pragma once
// 连接另一棵树T成为新的子树
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>*& T) {// 作为左子树
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
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>*& T) {// 作为右子树
	_size += T->_size;
	if (x->rc = T->_root)
		x->rc->parent = x;
	updateHeightAbove(x);
	T->_root = nullptr;
	T->_size = 0;
	T = nullptr;
	return x;
}