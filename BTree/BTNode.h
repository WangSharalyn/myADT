#pragma once
#include "../myADT/Vector.h"
#define BTNodePosi(T) BTNode<T>*

template <typename T> struct BTNode {
	//成员
	BTNodePosi(T) parent; // 父节点
	Vector<T> key; // 关键码向量
	Vector<BTNodePosi(T)> child; // 孩子向量，比关键码向量长度多1
	// 构造函数(注意：BTNode 只能作为根节点创建，而且初始时0个关键码和1个空孩子指针）
	BTNode() { parent = nullptr; child.insert(nullptr, 0); }
	BTNode(T e, BTNodePosi(T) lc = nullptr, BTNodePosi(T) rc = nullptr) {
		parent = nullptr; // 作为根节点，而且初始时只有一个关键码
		key.insert(e, 0);
		child.insert(lc, 0);
		child.insert(rc, 1); // 两个孩子
		if (lc) lc->parent = this;
		if (rc) rc->parent = this;
	}
};