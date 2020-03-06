#pragma once
// 双向链表节点

typedef int Rank;
#define ListNodePosi(T) listNode<T>*

template <typename T> struct listNode
{
	ListNodePosi(T) pred; // 前驱
	ListNodePosi(T) succ; // 后继
	T data; // 数据域
	// 构造函数
	listNode() = default; // header和trailer构造
	listNode(T e, ListNodePosi(T) p = nullptr, ListNodePosi(T) s = nullptr)
		: pred{p}, succ{s}, data{e} {}
};