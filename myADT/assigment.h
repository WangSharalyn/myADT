#pragma once
// 深拷贝
template <typename T>
Vector<T>& Vector<T>::operator= (const Vector<T>& A) {
	if (_elem) delete[]_elem; // 释放原有内容
	copyFrom(A._elem, 0, A._size);
	return *this;
}