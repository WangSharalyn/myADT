#pragma once
// Vector

typedef int Rank; // 秩
#define DEFAULT_CAPACITY 20 // 默认的初始容量
#include <iostream>

template <typename T> class Vector
{
public:
	// 构造函数
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
	// 析构函数
	~Vector() { delete[] _elem; };
	// 只读访问函数
	Rank size() { return _size; } // 返回规模
	bool empty() { return !_size; } // 判空
	Rank find(const T& e, Rank lo, Rank hi) const; // 无序向量查找
	Rank find(const T& e) const {
		return (0 >= _size) ? -1 : find(e, 0, _size);
	}
	Rank search(const T& e, Rank lo, Rank hi) const; // 有序向量查找
	Rank search(const T& e) const {
		return (0 >= _size) ? -1 : search(e, 0, _size);
	}
	void printV(); // 打印Vector元素
	// 可写访问接口
	T remove(Rank r); // 删除秩为r的元素
	int remove(Rank lo, Rank hi); // 删除区间[lo, hi）的元素
	T& operator[] (Rank r); // 重载下标运算符
	const T& operator[] (Rank r) const;
	Vector<T>& operator= (const Vector<T>& A); // 重载赋值运算符 
	Rank insert(const T& e, Rank r); // 插入元素
	Rank insert(const T& e) { return insert(e, _size); } // 默认插入最后，相当于push_back
	void sort(Rank lo, Rank hi); // [lo, hi)排序
	void sort() { sort(0, _size); }
	int deduplicate(); // 无序向量唯一化
	int uniquify(); //有序向量唯一化
private:
	Rank _size; // 规模
	int _capacity; // 容量
	T* _elem; // 数据区域
	void copyFrom(const T* A, Rank lo, Rank hi);// 复制区间[lo, hi)
	Rank binSearch_A(const T& e, Rank lo, Rank hi) const; // 二分查找
	Rank binSearch_B(const T& e, Rank lo, Rank hi) const;
	Rank binSearch_C(const T& e, Rank lo, Rank hi) const;
	void bubbleSort_A(Rank lo, Rank hi); // 起泡排序
	void bubbleSort_B(Rank lo, Rank hi); // 起泡排序版本B
	void bubbleSort_C(Rank lo, Rank hi); // 起泡排序版本C
	bool bubble_B(Rank lo, Rank hi);
	Rank bubble_C(Rank lo, Rank hi);
	void mergeSort(Rank lo, Rank hi); // 归并排序
	void merge(Rank lo, Rank hi, Rank mi); // 归并
	void swap(T& a, T& b); // 交换
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