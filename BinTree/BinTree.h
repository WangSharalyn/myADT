#pragma once
#include "BinNode.h"

template <typename T> class BinTree {
public:
	BinTree():_size{0}, _root{nullptr}{} // ���캯��
	~BinTree() { if (0 < _size) remove(_root); } // ��������
	void traPreorder_I() { _root->traversalPreorder_I(_root); }// ǰ�����
	void traPreorder_R() { _root->traversalPreorder_R(_root); }
	void traInorder_I() { _root->traversalInorder_I(_root); }// �������
	void traInorder_R() { _root->traversalInorder_R(_root); }
	void traPostorder_I() { _root->traversalPostorder_I(_root); }//  �������
	void traPostorder_R() { _root->traversalPostorder_R(_root); }
	void traLevel() { _root->traversalLevel(_root); }// �������
	int remove(BinNodePosi(T) x); // ɾ����x�ڵ�Ϊ�������������ظ�����ԭ�ȵĹ�ģ
	int size(BinNodePosi(T) x); // ���ع�ģ
	int size() { return _size; }
	bool empty() { return !_size; } // �п�
	BinNodePosi(T) root() { return _root; } // ��������
	// �����½ڵ�
	BinNodePosi(T) insertAsRoot(const T& e);// ������ڵ�
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, const T& e); // ����x������
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, const T& e); // ����x���Һ���
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>*& T); // T��Ϊ���ӽ���
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>*& T); // T��Ϊ�Һ��ӽ���
protected:
	int _size; // ��ģ
	BinNodePosi(T) _root;// ���ڵ�
	virtual int updateHeight(BinNodePosi(T) x);// ���½ڵ�x�ĸ߶�
	void updateHeightAbove(BinNodePosi(T) x);// ���½ڵ�x�������ȵĸ߶�
};

#include "BinTree_remove.h"
#include "BinTree_updateHeight.h"
#include "BinTree_size.h"
#include "BinTree_insert.h"
#include "BinTree_attach.h"