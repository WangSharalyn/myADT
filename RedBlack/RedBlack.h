#pragma once
#include "../BST/BST.h"
template <typename T> class RedBlack :public BST<T> {
protected:
	void solveDoubleRed(BinNodePosi(T) x); // ˫������
	void solveDoubleBlack(BinNodePosi(T) x); // ˫������
	int updateHeight(BinNodePosi(T) x); // ���½ڵ�x�ĸ߶ȣ��˸߶�Ϊ�ڸ߶�
public:
	BinNodePosi(T) insert(const T& e); // ����
	bool remove(const T& e); // ɾ��
};

#include "RedBlack_macro.h"
#include "RedBlack_updateHeight.h"
#include "RedBlack_insert.h"
#include "RedBlack_solveDoubleRed.h"
#include "RedBlack_remove.h"
#include "RedBlack_solveDoubleBlack.h"