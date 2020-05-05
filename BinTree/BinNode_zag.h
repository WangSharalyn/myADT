#pragma once
template <typename T>
BinNodePosi(T) BinNode<T>::zag() {
	BinNodePosi(T) rChild = rc;
	rChild->parent = parent;
	if (parent) {
		(this == parent->rc) ? (parent->rc = rChild) : (parent->lc = rChild);
	}
	rc = rChild->lc;
	if (rc) rc->parent = this;
	rChild->lc = this;
// 更新高度
	parent = rChild;
}