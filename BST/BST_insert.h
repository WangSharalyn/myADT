#pragma once
template <typename T>
BinNodePosi(T) BST<T>::insert(const T& e) {
	BinNodePosi(T)& x = search(e);
	if (x) return x;// ȷ��Ŀ�겻���ڣ�_hot�ĳ�ʼֵ��Ϊnullptr
	x = new BinNode<T>(e, _hot);
	this->_size++;
	this->updateHightAbove(x); // ���¸߶�
	return x;
}