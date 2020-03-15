#pragma once
#include "../BinTree/BinTree.h"

template <typename T> class BST :public BinTree<T> {
public:
	virtual BinNodePosi(T) insert(const T& e); // ����
	virtual BinNodePosi(T)& search(const T& e); // ����
	virtual bool remove(const T& e); // ɾ��
protected:
	BinNodePosi(T) _hot; // ���нڵ�ĸ���
	BinNodePosi(T) connect34(// ��3+4���ع�
		BinNodePosi(T) a, BinNodePosi(T) b, BinNodePosi(T) c,
		BinNodePosi(T) T0, BinNodePosi(T) T1, BinNodePosi(T) T2, BinNodePosi(T) T3);
	BinNodePosi(T) rotateAt(BinNodePosi(T) x); // ��x���丸�ף��游��ת
};

#include "BST_insert.h"
#include "BST_search.h"
#include "BST_remove.h"