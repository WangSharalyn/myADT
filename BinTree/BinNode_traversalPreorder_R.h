#pragma once
// ��������ݹ��
template <typename T>
void BinNode<T>::traversalPreorder_R(BinNodePosi(T) x) {
	if (!x) return;
	std::cout << x->data << ' ';
	traversalPreorder_R(x->lc);
	traversalPreorder_R(x->rc);
}