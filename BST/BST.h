#pragma once
#include "../BinTree/BinTree.h"

template <typename T> class BST : public BinTree<T> {
protected:
	BinNodePosi(T) _hot; // 命中节点的父亲
	BinNodePosi(T) connect34(// 3 + 4 结构，联结3个节点和四颗子树
		BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
		BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T)
	);
	BinNodePosi(T) rotateAt(BinNodePosi(T) v);
public:
	virtual BinNodePosi(T)& search(const T& e); // 查找
	virtual BinNodePosi(T) insert(const T& e); // 插入
	virtual bool remove(const T& e); // 删除
};

#include "BST_search.h"
#include "BST_insert.h"
#include "BST_remove.h"
#include "BST_connect34.h"
#include "BST_rotateAt.h"