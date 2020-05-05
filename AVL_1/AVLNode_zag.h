#pragma once
template <typename T>
Position(T) AVLNode<T>::zag() {
	Position(T) rChild = rc;
	rc = rChild->lc;
	rChild->lc = this;
// 更新高度
	height = 1 + _max(stature(lc), stature(rc));
	rChild->height = 1 + _max(stature(rChild->lc), stature(rChild->rc));
	return rChild;
}