#pragma once
#include <iostream>
#include "../Stack/Stack_vector.h"
#include "../Queue/Queue_list.h"
// 二叉树节点，包括数据域，左子树，右子树，父节点，高度，深度
#define BinNodePosi(T) BinNode<T>*
#define stature(p) ((p)? (p->height) : -1) // 节点高度，空树高度为-1，一个节点高度为0
#define __max(a, b) (((a) > (b)) ? (a) : (b))
template <typename T> struct BinNode {
	BinNodePosi(T) parent; // 父亲
	BinNodePosi(T) lc; // 左孩子
	BinNodePosi(T) rc; // 右孩子
	T data; // 数据
	int height; // 高度
	// 构造函数
	BinNode() :  parent { nullptr }, lc{ nullptr }, rc{ nullptr }, height{ 0 } {}
	BinNode(T e, BinNodePosi(T) p = nullptr, BinNodePosi(T) l = nullptr, BinNodePosi(T) r = nullptr,
		int h = 0):
		data{e}, parent{p}, lc{l}, rc{r}, height{h} {}
	// 可写访问接口
	BinNodePosi(T) insertAsLc(const T& e);// 插入作为左孩子
	BinNodePosi(T) insertAsRc(const T& e); // 插入作为右孩子
	// 遍历
	void traversalPreorder_R(BinNodePosi(T) x); // 先序遍历递归版
	void traversalPreorder_I(BinNodePosi(T) x); // 先序遍历迭代版
	void traversalInorder_R(BinNodePosi(T) x); // 中序遍历递归版
	void traversalInorder_I(BinNodePosi(T) x); // 中序遍历迭代版
	void traversalPostorder_R(BinNodePosi(T) x); // 后序遍历递归版
	void traversalPostorder_I(BinNodePosi(T) x); // 后序遍历迭代版
	void traversalLevel(BinNodePosi(T) x); // 层序遍历
	// 只读
	int size();
	BinNodePosi(T) succ(); // 中序遍历的后继
	////
	BinNodePosi(T) zig(); // 顺时针旋转
	BinNodePosi(T) zag(); // 逆时针旋转
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
#include "BinNode_size.h"
#include "BinNode_succ.h"
#include "BinNode_zig.h"
#include "BinNode_zag.h"