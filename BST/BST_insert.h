#pragma once
template <typename T>
BinNodePosi(T) BST<T>::insert(const T& e) {
	BinNodePosi(T)& x = search(e);
	if (x) return x;// 确认目标不存在，_hot的初始值设为nullptr
	x = new BinNode<T>(e, _hot);
	this->_size++;
	this->updateHightAbove(x); // 更新高度
	return x;
}