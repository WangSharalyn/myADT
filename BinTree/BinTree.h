#pragma once
#include "BinNode.h"

template <typename T> class BinTree {
public:
	BinTree():_size{0}, _root{nullptr}{} // 构造函数
	~BinTree() { if (0 < _size) remove(_root); } // 析构函数
	void traPreorder_I() { _root->traversalPreorder_I(_root); }// 前序遍历
	void traPreorder_R() { _root->traversalPreorder_R(_root); }
	void traInorder_I() { _root->traversalInorder_I(_root); }// 中序遍历
	void traInorder_R() { _root->traversalInorder_R(_root); }
	void traPostorder_I() { _root->traversalPostorder_I(_root); }//  后序遍历
	void traPostorder_R() { _root->traversalPostorder_R(_root); }
	void traLevel() { _root->traversalLevel(_root); }// 层序遍历
	int remove(BinNodePosi(T) x); // 删除以x节点为根的子树，返回该子树原先的规模
	int size(BinNodePosi(T) x); // 返回规模
	int size() { return _size; }
	bool empty() { return !_size; } // 判空
	BinNodePosi(T) root() { return _root; } // 返回树根
	// 插入新节点
	BinNodePosi(T) insertAsRoot(const T& e);// 插入根节点
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, const T& e); // 插入x的左孩子
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, const T& e); // 插入x的右孩子
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>*& T); // T作为左孩子接入
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>*& T); // T作为右孩子接入
protected:
	int _size; // 规模
	BinNodePosi(T) _root;// 根节点
	virtual int updateHeight(BinNodePosi(T) x);// 更新节点x的高度
	void updateHeightAbove(BinNodePosi(T) x);// 更新节点x及其祖先的高度
};

#include "BinTree_remove.h"
#include "BinTree_updateHeight.h"
#include "BinTree_size.h"
#include "BinTree_insert.h"
#include "BinTree_attach.h"