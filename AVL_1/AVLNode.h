#pragma once
#define Position(T) AVLNode<T>*
template <typename T> struct AVLNode {
	T data; // ����
	Position(T) lc; // ����
	Position(T) rc; // �Һ���
	int height; // �߶�
// ���캯��
	AVLNode():lc(nullptr), rc(nullptr), height(0){}
	AVLNode(T e, Position(T) lc = nullptr, Position(T) rc = nullptr, int h = 0):
		data(e), lc(lc), rc(rc), height(h) {}
// ����
	Position(T) zig(); // ˳ʱ����ת
	Position(T) zag(); // ��ʱ����ת
	Position(T) zig_zag();
	Position(T) zag_zig();
};

#include "AVLNode_zig.h"
#include "AVLNode_zag.h"
#include "AVLNode_zig_zag.h"
#include "AVLNode_zag_zig.h"