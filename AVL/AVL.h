#pragma once
// AVL Ê÷
#include "../BST/BST.h"
template <typename T> class AVL :public BST<T> {
public:
	BinNodePosi(T) insert(const T& e) override;
	bool remove(const T& e) override;
};

#include "AVL_marco.h"
#include "AVL_insert.h"
#include "AVL_remove.h"