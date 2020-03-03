#pragma once

template <typename T>
Rank Vector<T>::binSearch_A(const T& e, Rank lo, Rank hi) const {// [lo, hi)�ڲ���Ԫ��e
	/* �汾A���ɹ��Ƚ�һ�Σ�ʧ�ܱȽ����Σ�����������֧*/
	Rank mi; 
	while (lo < hi) {
		mi = (lo + hi) >> 1;
		if (e < _elem[mi]) hi = mi; // [lo, mi)����
		else if (_elem[mi] < e) lo = mi + 1; // (mi, hi) ����
		else return mi;
	}
	return -1;
}

template <typename T>
Rank Vector<T>::binSearch_B(const T& e, Rank lo, Rank hi) const {
	/*������֧����汾A�Ƚ����ܸ�Ϊ�ȶ�*/
	Rank mi;
	while (1 < hi - lo) {
		mi = (lo + hi) >> 1;
		e < _elem[mi] ? hi = mi : lo = mi; // [lo, mi)��[mi, hi)�������
	}
	return e == _elem[lo] ? lo : -1;
}

template <typename T>
Rank Vector<T>::binSearch_C(const T& e, Rank lo, Rank hi) const {
	Rank mi;
	while (lo < hi) {
		mi = (lo + hi) >> 1;
		e < _elem[mi] ? hi = mi : lo = mi + 1; // [lo, mi)��(mi, hi)�������
	}
	return --lo; // lo-1Ϊ����e��Ԫ�ص������
}

template <typename T>
Rank Vector<T>::search(const T& e, Rank lo, Rank hi) const {
	return binSearch_C(e, lo, hi);
}