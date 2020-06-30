#pragma once
#include "../BST/BST.h"
template <typename T> class RedBlack :public BST<T> {
protected:
	void solveDoubleRed(BinNodePosi(T) x); // 双红修正
	void solveDoubleBlack(BinNodePosi(T) x); // 双黑修正
	int updateHeight(BinNodePosi(T) x); // 更新节点x的高度，此高度为黑高度
public:
	BinNodePosi(T) insert(const T& e); // 插入
	bool remove(const T& e); // 删除
};

#include "RedBlack_macro.h"
#include "RedBlack_updateHeight.h"
#include "RedBlack_insert.h"
#include "RedBlack_solveDoubleRed.h"
#include "RedBlack_remove.h"
#include "RedBlack_solveDoubleBlack.h"