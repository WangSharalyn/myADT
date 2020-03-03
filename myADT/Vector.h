#pragma once
// Vector

typedef int Rank; // ��
#define DEFAULT_CAPACITY 20 // Ĭ�ϵĳ�ʼ����
#include <iostream>

template <typename T> class Vector
{
public:
	// ���캯��
	Vector() :_size(0), _capacity(DEFAULT_CAPACITY) {
		_elem = new T[_capacity];
	}
	Vector(int s, T v) :_size(s), _capacity(DEFAULT_CAPACITY) { // assert(0<=s<DEFAULT_CAPACITY)
		_elem = new T[_capacity];
		for (int i = 0; i < _size; _elem[i++] = v)
			;
	}
	Vector(const T* A, Rank lo, Rank hi) { copyFrom(A, lo, hi); }
	Vector(const T* A, Rank n) { copyFrom(A, 0, n); }
	Vector(const Vector<T>& A) { copyFrom(A._elem, 0, A._size); }
	Vector(const Vector<T>& A, Rank lo, Rank hi) { copyFrom(A._elem, lo, hi); }
	// ��������
	~Vector() { delete[] _elem; };
	// ֻ�����ʺ���
	Rank size() { return _size; } // ���ع�ģ
	bool empty() { return !_size; } // �п�
	Rank find(const T& e, Rank lo, Rank hi) const; // ������������
	Rank find(const T& e) const {
		return (0 >= _size) ? -1 : find(e, 0, _size);
	}
	Rank search(const T& e, Rank lo, Rank hi) const; // ������������
	Rank search(const T& e) const {
		return (0 >= _size) ? -1 : search(e, 0, _size);
	}
	void printV(); // ��ӡVectorԪ��
	// ��д���ʽӿ�
	T remove(Rank r); // ɾ����Ϊr��Ԫ��
	int remove(Rank lo, Rank hi); // ɾ������[lo, hi����Ԫ��
	T& operator[] (Rank r); // �����±������
	const T& operator[] (Rank r) const;
	Vector<T>& operator= (const Vector<T>& A); // ���ظ�ֵ����� 
	Rank insert(const T& e, Rank r); // ����Ԫ��
	Rank insert(const T& e) { return insert(e, _size); } // Ĭ�ϲ�������൱��push_back
	void sort(Rank lo, Rank hi); // [lo, hi)����
	void sort() { sort(0, _size); }
	int deduplicate(); // ��������Ψһ��
	int uniquify(); //��������Ψһ��
private:
	Rank _size; // ��ģ
	int _capacity; // ����
	T* _elem; // ��������
	void copyFrom(const T* A, Rank lo, Rank hi);// ��������[lo, hi)
	Rank binSearch_A(const T& e, Rank lo, Rank hi) const; // ���ֲ���
	Rank binSearch_B(const T& e, Rank lo, Rank hi) const;
	Rank binSearch_C(const T& e, Rank lo, Rank hi) const;
	void bubbleSort_A(Rank lo, Rank hi); // ��������
	void bubbleSort_B(Rank lo, Rank hi); // ��������汾B
	void bubbleSort_C(Rank lo, Rank hi); // ��������汾C
	bool bubble_B(Rank lo, Rank hi);
	Rank bubble_C(Rank lo, Rank hi);
	void mergeSort(Rank lo, Rank hi); // �鲢����
	void merge(Rank lo, Rank hi, Rank mi); // �鲢
	void swap(T& a, T& b); // ����
};

#include "copyFrom.h"
#include "find.h"
#include "search.h"
#include "remove.h"
#include "bracket.h"
#include "assigment.h"
#include "insert.h"
#include "sort.h"
#include "swap.h"
#include "printVector.h"
#include "deduplicate.h"
#include "uniquify.h"