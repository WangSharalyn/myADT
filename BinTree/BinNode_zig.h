#pragma once
template <typename T>
BinNodePosi(T) BinNode<T>::zig() {// ˳ʱ����ת
	BinNodePosi(T) lChild = lc;
	lChild->parent = parent;
	if (parent) {
		(this == parent->rc) ? (parent->rc = lChild) : (parent->lc = lChild);
	}
	lc = lChild->rc;
	if (lc) lc->parent = this;
	lChild->rc = this;
	this->parent = lChild;
// TODO:���¸߶�
	height = 1 + __max(stature(lc), stature(rc));

	return lChild;
}