#pragma once
// 插入
template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRoot(const T& e) {// 插入根节点
	_size = 1;
	return _root = new BinNode<T>(e);
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsLC(BinNodePosi(T) x, const T& e) {// 插入x的左孩子
	_size++;
	x->insertAsLc(e);
	updateHeightAbove(x);
	return x->lc;
}

template <typename T>
BinNodePosi(T) BinTree<T>::insertAsRC(BinNodePosi(T) x, const T& e) { // 插入x的左孩子
	_size++;
	x->insertAsRc(e);
	updateHeightAbove(x);
	return x->rc;
}