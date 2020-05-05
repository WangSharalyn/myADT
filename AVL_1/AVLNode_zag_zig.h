#pragma once
template <typename T>
Position(T) AVLNode<T>::zag_zig() {
	rc = rc->zig();
	return zag();
}