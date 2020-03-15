#pragma once
// 顺时针旋转
template <typename T>
BinNodePosi(T) BinNode<T>::zig() {
	BinNodePosi(T) lchild = lc;
	lchild->parent = parent;
	if(lchild->parent)
		((this == lchild->parent->rc) ? lchild->parent->rc : lchild->parent->lc) = lchild;
	lc = lchild->rc;
	if (lc) lc->parent = this;
	// 更新高度
	height = 1 + __max(stature(lc), stature(rc));
	lchild->height = 1 + __max(stature(lchild->lc), stature(lchild->rc));
	for (BinNodePosi(T) x = lchild->parent; x; x->parent)
		if (x->height == __max(stature(x->lc), stature(x->rc)))
			break;
		else
			x->height = __max(stature(x->lc), stature(x->rc));
	return lchild;
}