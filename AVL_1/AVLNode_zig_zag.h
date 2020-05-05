#pragma once
template <typename T>
Position(T) AVLNode<T>::zig_zag() {
	lc = lc->zag();
	return zig();
}