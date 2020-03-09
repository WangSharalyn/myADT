#pragma once
#include <iostream>
#include "../Stack/Stack_vector.h"
#include "../Queue/Queue_list.h"
// �������ڵ㣬�����������������������������ڵ㣬�߶ȣ����
#define BinNodePosi(T) BinNode<T>*

template <typename T> struct BinNode {
	BinNodePosi(T) parent; // ����
	BinNodePosi(T) lc; // ����
	BinNodePosi(T) rc; // �Һ���
	T data; // ����
	int height; // �߶�
	// ���캯��
	BinNode() :  parent { nullptr }, lc{ nullptr }, rc{ nullptr }, height{ 0 } {}
	BinNode(T e, BinNodePosi(T) p = nullptr, BinNodePosi(T) l = nullptr, BinNodePosi(T) r = nullptr,
		int h = 0):
		data{e}, parent{p}, lc{l}, rc{r}, height{h} {}
	// ��д���ʽӿ�
	BinNodePosi(T) insertAsLc(const T& e);// ������Ϊ����
	BinNodePosi(T) insertAsRc(const T& e); // ������Ϊ�Һ���
	// ����
	void traversalPreorder_R(BinNodePosi(T) x); // ��������ݹ��
	void traversalPreorder_I(BinNodePosi(T) x); // �������������
	void traversalInorder_R(BinNodePosi(T) x); // ��������ݹ��
	void traversalInorder_I(BinNodePosi(T) x); // �������������
	void traversalPostorder_R(BinNodePosi(T) x); // ��������ݹ��
	void traversalPostorder_I(BinNodePosi(T) x); // �������������
	void traversalLevel(BinNodePosi(T) x); // �������
};

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsLc(const T& e) {
	return lc = new BinNode(e, this);
}

template <typename T>
BinNodePosi(T) BinNode<T>::insertAsRc(const T& e) {
	return rc = new BinNode(e, this);
}

#include "BinNode_traversalPreorder_R.h"
#include "BinNode_traversalPreorder_I.h"
#include "BinNode_traversalInorder_R.h"
#include "BinNode_traversalInorder_I.h"
#include "BinNode_traversalPostorder_R.h"
#include "BinNode_traversalPostorder_I.h"
#include "BinNode_traversalLevel.h"