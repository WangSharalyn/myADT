#pragma once
#include "../BinTree/BinTree.h"

template <typename T> class BST :public BinTree<T> {
public:
	virtual BinNodePosi(T) insert(const T& e); // 插入
	virtual BinNodePosi(T)& search(const T& e); // 查找
	virtual bool remove(const T& e); // 删除
protected:
	BinNodePosi(T) _hot; // 命中节点的父亲
	BinNodePosi(T) connect34(// “3+4”重构
		BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
		BinNodePosi(T) T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3);
	BinNodePosi(T) rotateAt(BinNodePosi(T) x); // 对x及其父亲，祖父旋转
};

#include "BST_insert.h"
#include "BST_search.h"
#include "BST_remove.h"