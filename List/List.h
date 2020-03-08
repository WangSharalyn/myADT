#pragma once
// List双向链表
#include "listNode.h"

template <typename T> class List
{
public:
	//构造函数
	List() { init(); } // 默认构造函数
	List(const List<T>& L); // 拷贝构造函数
	// 析构函数
	~List();
	// 只读访问接口
	Rank size() { return _size; } // 规模
	ListNodePosi(T) first() const { return header->succ; } // 首节点
	ListNodePosi(T) last() const { return trailer->pred; } // 末节点
	T& operator[](Rank r); // 寻秩访问，效率低O(n)
	ListNodePosi(T) find(const T& e, int n, ListNodePosi(T) p) const;// 无序列表查找
	ListNodePosi(T) find(const T& e) const { 
		return find(e, _size, trailer); 
	}
	ListNodePosi(T) search(const T& e, int n, ListNodePosi(T) p) const;// 有序列表查找，返回不大于e的最大秩
	ListNodePosi(T) search(const T& e) const {
		return search(e, _size, trailer);
	}
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n); // p及后继n-1中最大值
	ListNodePosi(T) selectMax() {
		return selectMax(first(), _size);
	}
	void printL(); // 打印数据域
	// 可写访问接口
	T remove(ListNodePosi(T) p); // 删除合法位置p处的节点，返回被删除节点的值
	ListNodePosi(T) insertAsFirst(const T& e); // 插入首节点
	ListNodePosi(T) insertAsLast(const T& e); // 插入末节点
	ListNodePosi(T) insertA(ListNodePosi(T) p, const T& e); // After
	ListNodePosi(T) insertB(ListNodePosi(T) p, const T& e); // Before
	void selectionSort(ListNodePosi(T) p, int n); // 对p开始的n个节点选择排序
	void selectionSort() {
		selectionSort(first(), _size);
	}
	void insertionSort(ListNodePosi(T) p, int n); // 插入排序
	void insertionSort() {
		insertionSort(first(), _size);
	}
	void mergeSort(ListNodePosi(T) p, int n); // 归并排序
	void mergeSort() {
		mergeSort(first(), _size);
	}
	int deduplicate(); // 无序去重
	int uniquify(); // 有序去重
protected:
	Rank _size; // 规模
	ListNodePosi(T) header; // 头哨兵
	ListNodePosi(T) trailer; // 尾哨兵
	void init(); // 列表初始化
	int clear(); // 清除所有节点
	void copyNodes(ListNodePosi(T) p, int n); // 从p开始拷贝n项
	// TODO:归并
	void merge(ListNodePosi(T) p, int n, List<T> L, ListNodePosi(T) q, int m);
};

#include "listInitialize.h"
#include "remove.h"
#include "clear.h"
#include "destructor.h"
#include "constructor.h"
#include "insert.h"
#include "printList.h"
#include "copyNodes.h"
#include "bracket.h"
#include "find.h"
#include "search.h"
#include "deduplicate.h"
#include "uniquify.h"
#include "selectMax.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "mergeSort.h"