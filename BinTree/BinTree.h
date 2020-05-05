#pragma once
#include "BinNode.h"

template <typename T> class BinTree {
protected:
	int _size; // ��ģ
	BinNodePosi(T) _root;// ���ڵ�
	virtual int updateHeight(BinNodePosi(T) x); // ���½ڵ�x�ĸ߶�
	void updateHightAbove(BinNodePosi(T) x); // ���½ڵ�x�������ȵĸ߶�
public:
	BinTree(): _size(0), _root(nullptr){} // ���캯��
	~BinTree() { if (0 < _size) remove(_root); } // ��������
	int size() const { return _size; } // ��ģ
	bool empty() const { return _size == 0; } // �п�
	BinNodePosi(T) root() const { return _root; } // ��������
	BinNodePosi(T) insertAsRoot(const T& e); // ��������
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, const T& e); // e��Ϊx�����ӱ�����
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, const T& e); // e��Ϊx���Һ��ӱ�����
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>*& S); // T��Ϊ����������
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>*& T); // T��Ϊ����������
	int remove(BinNodePosi(T) x); // ɾ����λ��xΪ��������������ԭ�������Ĺ�ģ
	void travLevel() { if (_root) _root->travLevel(); }// �������
	void travPre() { if (_root) _root->travPre(); } // �������
	void travIn() { if (_root) _root->travIn(); } // �������
	void travPost() { if (_root) _root->travPost(); } // �������
};

#include "BinTree_updateHeight.h"
#include "BinTree_insert.h"
#include "BinTree_remove.h"
#include "BinTree_attach.h"