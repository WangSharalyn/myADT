#pragma once
// ¿½±´¹¹Ôìº¯Êý
template <typename T>
List<T>::List(const List<T>& L) {
	copyNodes(L.first(), L._size());
}