#pragma once
#include <iostream>
template <typename T>
Rank Vector<T>::find(const T& e, Rank lo, Rank hi) const { // 无序向量的顺序查找：返回最后一个元素e的位置；失败时，返回lo-1
	while ((lo < hi--) && (e != _elem[hi]));
	return hi;
}
