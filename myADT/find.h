#pragma once
#include <iostream>
template <typename T>
Rank Vector<T>::find(const T& e, Rank lo, Rank hi) const { // ����������˳����ң��������һ��Ԫ��e��λ�ã�ʧ��ʱ������lo-1
	while ((lo < hi--) && (e != _elem[hi]));
	return hi;
}
