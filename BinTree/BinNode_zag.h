#pragma once
// 逆时针旋转
template <typename T>
BinNodePosi(T) BinNode<T>::zag() {
	BinNodePosi(T) rchild = rc;
	rchild->parent = parent;
	if (rchild->parent)
		((this == rchild->parent->lc) ? rchild->parent->lc : rchild->parent->rc) = rchild;
	rc = rchild->lc;
	if (lc) lc->parent = this;
	rchild->lc = this;
	this->parent = rchild;
	// 更新高度
	height = 1 + __max(stature(lc), stature(rc));
	for (BinNodePosi(T) x = rchild->parent; x; x = x->parent)
		if (x->height == __max(stature(x->lc), stature(x->rc))+1)
			break;
		else
			x->height = __max(stature(x->lc), stature(x->rc)) + 1;
	return rchild;
}