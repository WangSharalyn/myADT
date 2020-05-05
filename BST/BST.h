#pragma once
#include "../BinTree/BinTree.h"

template <typename T> class BST : public BinTree<T> {
protected:
	BinNodePosi(T) _hot; // ���нڵ�ĸ���
	BinNodePosi(T) connect34(// 3 + 4 �ṹ������3���ڵ���Ŀ�����
		BinNodePosi(T), BinNodePosi(T), BinNodePosi(T),
		BinNodePosi(T), BinNodePosi(T), BinNodePosi(T), BinNodePosi(T)
	);
	BinNodePosi(T) rotateAt(BinNodePosi(T) v);
public:
	virtual BinNodePosi(T)& search(const T& e); // ����
	virtual BinNodePosi(T) insert(const T& e); // ����
	virtual bool remove(const T& e); // ɾ��
};

#include "BST_search.h"
#include "BST_insert.h"
#include "BST_remove.h"
#include "BST_connect34.h"
#include "BST_rotateAt.h"