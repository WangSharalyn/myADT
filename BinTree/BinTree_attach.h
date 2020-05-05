#pragma once
template <typename T>
BinNodePosi(T) BinTree<T>::attachAsLC(BinNodePosi(T) x, BinTree<T>*& S) {
	if (x->lc = S->_root) x->lc->parent = x; // 接入
	_size += S->_size;// 更新规模
	updateHightAbove(x);// 更新x及其祖先的高度
	S->_root = nullptr;
	S->_size = 0;
	S = nullptr;
	return x;
}

template <typename T>
BinNodePosi(T) BinTree<T>::attachAsRC(BinNodePosi(T) x, BinTree<T>*& S) {
	if (x->rc = S->_root) x->rc->parent = x;// 接入
	_size += S->_size;
	updateHightAbove(x);
	S->_root = nullptr;
	S->_size = 0;
	S = nullptr;
	return x;
}