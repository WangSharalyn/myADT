#pragma once
template <typename T>
BinNodePosi(T) RedBlack<T>::insert(const T& e) {
	BinNodePosi(T)& x = search(e); if (x) return x;
	x = new BinNode<T>(e, _hot, nullptr, nullptr, -1); _size++;
	BinNodePosi(T) xOld = x; solveDoubleRed(x); 
	return xOld;
}