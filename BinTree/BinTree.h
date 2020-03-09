#pragma once
#include "BinNode.h"

template <typename T> class BinTree {
public:
	BinTree():_size{0}, _root{nullptr}{}
	//TODO:��������
	~BinTree();
	void traPreorder_I() { _root->traversalPreorder_I(_root); }// ǰ�����
	void traPreorder_R() { _root->traversalPreorder_R(_root); }
	void traInorder_I() { _root->traversalInorder_I(_root); }// �������
	void traInorder_R() { _root->traversalInorder_R(_root); }
	void traPostorder_I() { _root->traversalPostorder_I(_root); }//  �������
	void traPostorder_R() { _root->traversalPostorder_R(_root); }
	void traLevel() { _root->traversalLevel(_root); }// �������
protected:
	int _size; // ��ģ
	BinNodePosi(T) _root;// ���ڵ�
};