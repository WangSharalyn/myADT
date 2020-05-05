#pragma once
#define Position(T) AVLNode<T>*
template <typename T> struct AVLNode {
	T data; // 数据
	Position(T) lc; // 左孩子
	Position(T) rc; // 右孩子
	int height; // 高度
// 构造函数
	AVLNode():lc(nullptr), rc(nullptr), height(0){}
	AVLNode(T e, Position(T) lc = nullptr, Position(T) rc = nullptr, int h = 0):
		data(e), lc(lc), rc(rc), height(h) {}
// 操作
	Position(T) zig(); // 顺时针旋转
	Position(T) zag(); // 逆时针旋转
	Position(T) zig_zag();
	Position(T) zag_zig();
};

#include "AVLNode_zig.h"
#include "AVLNode_zag.h"
#include "AVLNode_zig_zag.h"
#include "AVLNode_zag_zig.h"