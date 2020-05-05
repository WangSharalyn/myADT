#pragma once
#include "../myADT/Vector.h"
#define BTNodePosi(T) BTNode<T>*

template <typename T> struct BTNode {
	//��Ա
	BTNodePosi(T) parent; // ���ڵ�
	Vector<T> key; // �ؼ�������
	Vector<BTNodePosi(T)> child; // �����������ȹؼ����������ȶ�1
	// ���캯��(ע�⣺BTNode ֻ����Ϊ���ڵ㴴�������ҳ�ʼʱ0���ؼ����1���պ���ָ�룩
	BTNode() { parent = nullptr; child.insert(nullptr, 0); }
	BTNode(T e, BTNodePosi(T) lc = nullptr, BTNodePosi(T) rc = nullptr) {
		parent = nullptr; // ��Ϊ���ڵ㣬���ҳ�ʼʱֻ��һ���ؼ���
		key.insert(e, 0);
		child.insert(lc, 0);
		child.insert(rc, 1); // ��������
		if (lc) lc->parent = this;
		if (rc) rc->parent = this;
	}
};