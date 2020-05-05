#pragma once
#define stature(p) ((p)?((p)->height):(-1))
#define __max(a, b) (((a) > (b))?(a):(b))
#define BinNodePosi(T) BinNode<T>*
template <typename T> struct BinNode{
	typedef enum { RB_RED, RB_BLACK } RBColor;
// 成员
	T data; // 数据
	BinNodePosi(T) parent; // 父亲节点
	BinNodePosi(T) lc;
	BinNodePosi(T) rc; // 左右孩子
	int height; // 高度
	RBColor color; // 颜色(红黑树)
// 构造函数
	BinNode():parent(nullptr), lc(nullptr), rc(nullptr), height(0), color(RB_RED){}
	BinNode(T e, BinNodePosi(T) parent = nullptr, BinNodePosi(T) lc = nullptr, BinNodePosi(T) rc = nullptr, int h = 0, RBColor c = RB_RED):
		data(e), parent(parent), lc(lc), rc(rc), height(h), color(c){}
// 操作接口
	int size(); // 统计当前节点后代个数，以此节点为根的子树的规模
	BinNodePosi(T) insertAsLC(const T&); // 作为当前节点的左孩子插入
	BinNodePosi(T) insertAsRC(const T&); // 作为当前节点的右孩子插入
	BinNodePosi(T) succ(); // 中序遍历的直接后继
	void travLevel(); // 子树层序遍历
	void travPre(); // 子树先序遍历
	void travIn(); // 子树中序遍历
	void travPost(); // 子树后序遍历
// 旋转操作
	BinNodePosi(T) zig(); // 顺时针旋转
	BinNodePosi(T) zag(); // 逆时针旋转
};

#include "BinNode_size.h"
#include "BinNode_insert.h"
#include "BinNode_succ.h"
#include "BinNode_travLevel.h"
#include "BinNode_travPre.h"
#include "BinNode_travIn.h"
#include "BinNode_travePost.h"
#include "BinNode_zig.h"
#include "BinNode_zag.h"