#pragma once
// List˫������
#include "listNode.h"

template <typename T> class List
{
public:
	//���캯��
	List() { init(); } // Ĭ�Ϲ��캯��
	List(const List<T>& L); // �������캯��
	// ��������
	~List();
	// ֻ�����ʽӿ�
	Rank size() { return _size; } // ��ģ
	ListNodePosi(T) first() const { return header->succ; } // �׽ڵ�
	ListNodePosi(T) last() const { return trailer->pred; } // ĩ�ڵ�
	T& operator[](Rank r); // Ѱ�ȷ��ʣ�Ч�ʵ�O(n)
	ListNodePosi(T) find(const T& e, int n, ListNodePosi(T) p) const;// �����б����
	ListNodePosi(T) find(const T& e) const { 
		return find(e, _size, trailer); 
	}
	ListNodePosi(T) search(const T& e, int n, ListNodePosi(T) p) const;// �����б���ң����ز�����e�������
	ListNodePosi(T) search(const T& e) const {
		return search(e, _size, trailer);
	}
	ListNodePosi(T) selectMax(ListNodePosi(T) p, int n); // p�����n-1�����ֵ
	ListNodePosi(T) selectMax() {
		return selectMax(first(), _size);
	}
	void printL(); // ��ӡ������
	// ��д���ʽӿ�
	T remove(ListNodePosi(T) p); // ɾ���Ϸ�λ��p���Ľڵ㣬���ر�ɾ���ڵ��ֵ
	ListNodePosi(T) insertAsFirst(const T& e); // �����׽ڵ�
	ListNodePosi(T) insertAsLast(const T& e); // ����ĩ�ڵ�
	ListNodePosi(T) insertA(ListNodePosi(T) p, const T& e); // After
	ListNodePosi(T) insertB(ListNodePosi(T) p, const T& e); // Before
	void selectionSort(ListNodePosi(T) p, int n); // ��p��ʼ��n���ڵ�ѡ������
	void selectionSort() {
		selectionSort(first(), _size);
	}
	void insertionSort(ListNodePosi(T) p, int n); // ��������
	void insertionSort() {
		insertionSort(first(), _size);
	}
	void mergeSort(ListNodePosi(T) p, int n); // �鲢����
	void mergeSort() {
		mergeSort(first(), _size);
	}
	int deduplicate(); // ����ȥ��
	int uniquify(); // ����ȥ��
protected:
	Rank _size; // ��ģ
	ListNodePosi(T) header; // ͷ�ڱ�
	ListNodePosi(T) trailer; // β�ڱ�
	void init(); // �б��ʼ��
	int clear(); // ������нڵ�
	void copyNodes(ListNodePosi(T) p, int n); // ��p��ʼ����n��
	// TODO:�鲢
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