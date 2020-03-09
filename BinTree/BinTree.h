#pragma once
#include "BinNode.h"

template <typename T> class BinTree {
public:
	BinTree():_size{0}, _root{nullptr}{}
	//TODO:析构函数
	~BinTree();
	void traPreorder_I() { _root->traversalPreorder_I(_root); }// 前序遍历
	void traPreorder_R() { _root->traversalPreorder_R(_root); }
	void traInorder_I() { _root->traversalInorder_I(_root); }// 中序遍历
	void traInorder_R() { _root->traversalInorder_R(_root); }
	void traPostorder_I() { _root->traversalPostorder_I(_root); }//  后序遍历
	void traPostorder_R() { _root->traversalPostorder_R(_root); }
	void traLevel() { _root->traversalLevel(_root); }// 层序遍历
protected:
	int _size; // 规模
	BinNodePosi(T) _root;// 根节点
};