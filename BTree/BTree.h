#pragma once
#include "BTNode.h"
template <typename T> class BTree {
protected:
	int _size; // ��Źؼ�������
	int _order; // B-���Ľ״Σ� ����Ϊ3��������ʱָ�һ�㲻���޸�
	BTNodePosi(T) _root; // ���ڵ�
	BTNodePosi(T) _hot; // BTree::search()�����ʵķǿգ��������գ��Ľڵ�λ��
	void solveOverflow(BTNodePosi(T)); // ����������֮��ķ��Ѵ���
	void solveUnderflow(BTNodePosi(T)); // ��ɾ��������֮��ĺϲ�����
public:
	BTree(int order = 3) :_order(order), _size(0) {// ���캯����Ĭ����ͽ�Ϊ3��
		_root = new BTNode<T>();
	}
	~BTree() { if (_root) delete _root; }// ��������
	int order() const { return _order; }
	int size() const { return _size; }
	BTNodePosi(T)& root() { return _root; }
	bool empty() { return !_root; }
	BTNodePosi(T) search(const T& e); // ����
	bool insert(const T& e); // ����
	bool remove(const T& e); // ɾ��
};

#include "BTree_search.h"
#include "BTree_insert.h"
#include "BTree_remove.h"
#include "BTree_solveOverflow.h"
#include "BTree_solveUnderflow.h"
