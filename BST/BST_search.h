#pragma once
#include "BST_searchIn_I.h"
#include "BST_searchIn_R.h"
template <typename T>
BinNodePosi(T)& BST<T>::search(const T& e) {
	switch (rand() % 2) {
	case 1: return searchIn_I(this->_root, e, this->_hot = nullptr);
	default: return searchIn_R(this->_root, e, this->_hot = nullptr);
	}
}