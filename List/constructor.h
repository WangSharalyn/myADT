#pragma once
// �������캯��
template <typename T>
List<T>::List(const List<T>& L) {
	copyNodes(L.first(), L._size());
}