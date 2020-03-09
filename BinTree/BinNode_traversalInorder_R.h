#pragma once
// ÖĞĞò±éÀúµİ¹é°æ
template <typename T>
void BinNode<T>::traversalInorder_R(BinNodePosi(T) x) {
	if (!x) return;
	traversalInorder_R(x->lc);
	std::cout << x->data << ' ';
	traversalInorder_R(x->rc);
}