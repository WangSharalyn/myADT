#pragma once
// ��������ݹ��
template <typename T>
void BinNode<T>::traversalPostorder_R(BinNodePosi(T) x) {
	if (!x) return;
	traversalPostorder_R(x->lc);
	traversalPostorder_R(x->rc);
	std::cout << x->data << ' ';
}