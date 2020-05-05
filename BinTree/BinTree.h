#pragma once
#include "BinNode.h"

template <typename T> class BinTree {
protected:
	int _size; // 规模
	BinNodePosi(T) _root;// 根节点
	virtual int updateHeight(BinNodePosi(T) x); // 更新节点x的高度
	void updateHightAbove(BinNodePosi(T) x); // 更新节点x及其祖先的高度
public:
	BinTree(): _size(0), _root(nullptr){} // 构造函数
	~BinTree() { if (0 < _size) remove(_root); } // 析构函数
	int size() const { return _size; } // 规模
	bool empty() const { return _size == 0; } // 判空
	BinNodePosi(T) root() const { return _root; } // 返回树根
	BinNodePosi(T) insertAsRoot(const T& e); // 插入树根
	BinNodePosi(T) insertAsLC(BinNodePosi(T) x, const T& e); // e作为x的左孩子被插入
	BinNodePosi(T) insertAsRC(BinNodePosi(T) x, const T& e); // e作为x的右孩子被插入
	BinNodePosi(T) attachAsLC(BinNodePosi(T) x, BinTree<T>*& S); // T作为左子树接入
	BinNodePosi(T) attachAsRC(BinNodePosi(T) x, BinTree<T>*& T); // T作为右子树接入
	int remove(BinNodePosi(T) x); // 删除以位置x为根的子树，返回原来子树的规模
	void travLevel() { if (_root) _root->travLevel(); }// 层序遍历
	void travPre() { if (_root) _root->travPre(); } // 先序遍历
	void travIn() { if (_root) _root->travIn(); } // 中序遍历
	void travPost() { if (_root) _root->travPost(); } // 后序遍历
};

#include "BinTree_updateHeight.h"
#include "BinTree_insert.h"
#include "BinTree_remove.h"
#include "BinTree_attach.h"