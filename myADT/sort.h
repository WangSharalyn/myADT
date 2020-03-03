#pragma once
// 排序：起泡排序，归并排序

template <typename T>
void Vector<T>::bubbleSort_A(Rank lo, Rank hi) {// 普通起泡排序
	while (lo < --hi) {
		for (int i = lo + 1; i <= hi; i++) {
			if (_elem[i] < _elem[i-1])
				swap(_elem[i - 1], _elem[i]);
		}
	}
}

template <typename T>
bool Vector<T>::bubble_B(Rank lo, Rank hi) {
	bool sorted = true;
	while (++lo < hi) {
		if (_elem[lo] < _elem[lo - 1]) {
			sorted = false;
			swap(_elem[lo], _elem[lo - 1]);
		}
	}
	return sorted;
}

template <typename T>
void Vector<T>::bubbleSort_B(Rank lo, Rank hi) {
	while ((!bubble_B(lo, hi)));
}

template <typename T>
Rank Vector<T>::bubble_C(Rank lo, Rank hi) {
	Rank last = lo;
	while (++lo < hi) {
		if (_elem[lo] < _elem[lo-1]) {
			last = lo;
			swap(_elem[lo - 1], _elem[lo]);
		}
	}
	return last;
}

template <typename T>
void Vector<T>::bubbleSort_C(Rank lo, Rank hi) {
	while (lo < (hi = bubble_C(lo, hi)));
}

template <typename T>
void Vector<T>::mergeSort(Rank lo, Rank hi) {
	if (hi - lo < 2) return;
	Rank mi = (lo + hi) >> 1;
	mergeSort(lo, mi);
	mergeSort(mi, lo);
	merge(lo, hi, mi);
}

template <typename T>
void Vector<T>::merge(Rank lo, Rank hi, Rank mi) {// 有序向量的归并
	T* A = _elem + lo;
	Rank lb = mi - lo;
	T* B = new T[lb];
	Rank lc = hi - mi;
	T* C = _elem + mi;
	for (Rank i = 0; i < lb; i++) B[i] = A[i];
	for (Rank i = 0, j = 0, k = 0; j < lb; )// i--A, j--B, k--C
		A[i++] = (lc <= k || B[j] <= C[k]) ? B[j++] : C[k++];
	delete[] B;
}

template <typename T>
void Vector<T>::sort(Rank lo, Rank hi)
{
	mergeSort(lo, hi);
}