#pragma once
// ˫������ڵ�

typedef int Rank;
#define ListNodePosi(T) listNode<T>*

template <typename T> struct listNode
{
	ListNodePosi(T) pred; // ǰ��
	ListNodePosi(T) succ; // ���
	T data; // ������
	// ���캯��
	listNode() = default; // header��trailer����
	listNode(T e, ListNodePosi(T) p = nullptr, ListNodePosi(T) s = nullptr)
		: pred{p}, succ{s}, data{e} {}
};