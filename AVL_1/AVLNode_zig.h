#pragma once
template <typename T>
inline int stature(Position(T) x) {
	return (x) ? x->height : -1;
}

template <typename T>
inline T _max(T a, T b) {
	return (a > b) ? a : b;
}

template <typename T>
Position(T) AVLNode<T>::zig() {
	Position(T) lChild = lc;
	lc = lChild->rc;
	lChild->rc = this;
// 更新高度
	height = 1 + _max(stature(rc), stature(lc));
	lChild->height = 1 + _max(stature(lChild->rc), stature(lChild->lc));
	return lChild;
}