#pragma once

template <typename T>
Rank Vector<T>::binSearch_A(const T& e, Rank lo, Rank hi) const {// [lo, hi)内查找元素e
	/* 版本A：成功比较一次，失败比较两次，共有三个分支*/
	Rank mi; 
	while (lo < hi) {
		mi = (lo + hi) >> 1;
		if (e < _elem[mi]) hi = mi; // [lo, mi)查找
		else if (_elem[mi] < e) lo = mi + 1; // (mi, hi) 查找
		else return mi;
	}
	return -1;
}

template <typename T>
Rank Vector<T>::binSearch_B(const T& e, Rank lo, Rank hi) const {
	/*两个分支，与版本A比较性能更为稳定*/
	Rank mi;
	while (1 < hi - lo) {
		mi = (lo + hi) >> 1;
		e < _elem[mi] ? hi = mi : lo = mi; // [lo, mi)或[mi, hi)区间查找
	}
	return e == _elem[lo] ? lo : -1;
}

template <typename T>
Rank Vector<T>::binSearch_C(const T& e, Rank lo, Rank hi) const {
	Rank mi;
	while (lo < hi) {
		mi = (lo + hi) >> 1;
		e < _elem[mi] ? hi = mi : lo = mi + 1; // [lo, mi)或(mi, hi)区间查找
	}
	return --lo; // lo-1为大于e的元素的最大秩
}

template <typename T>
Rank Vector<T>::search(const T& e, Rank lo, Rank hi) const {
	return binSearch_C(e, lo, hi);
}