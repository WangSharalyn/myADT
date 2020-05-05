#pragma once
#define stature(p) ((p)?((p)->height):(-1))
#define __max(a, b) (((a) > (b))?(a):(b))
#define BinNodePosi(T) BinNode<T>*
template <typename T> struct BinNode{
	typedef enum { RB_RED, RB_BLACK } RBColor;
// ��Ա
	T data; // ����
	BinNodePosi(T) parent; // ���׽ڵ�
	BinNodePosi(T) lc;
	BinNodePosi(T) rc; // ���Һ���
	int height; // �߶�
	RBColor color; // ��ɫ(�����)
// ���캯��
	BinNode():parent(nullptr), lc(nullptr), rc(nullptr), height(0), color(RB_RED){}
	BinNode(T e, BinNodePosi(T) parent = nullptr, BinNodePosi(T) lc = nullptr, BinNodePosi(T) rc = nullptr, int h = 0, RBColor c = RB_RED):
		data(e), parent(parent), lc(lc), rc(rc), height(h), color(c){}
// �����ӿ�
	int size(); // ͳ�Ƶ�ǰ�ڵ����������Դ˽ڵ�Ϊ���������Ĺ�ģ
	BinNodePosi(T) insertAsLC(const T&); // ��Ϊ��ǰ�ڵ�����Ӳ���
	BinNodePosi(T) insertAsRC(const T&); // ��Ϊ��ǰ�ڵ���Һ��Ӳ���
	BinNodePosi(T) succ(); // ���������ֱ�Ӻ��
	void travLevel(); // �����������
	void travPre(); // �����������
	void travIn(); // �����������
	void travPost(); // �����������
// ��ת����
	BinNodePosi(T) zig(); // ˳ʱ����ת
	BinNodePosi(T) zag(); // ��ʱ����ת
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