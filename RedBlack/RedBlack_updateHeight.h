#pragma once
template <typename T>
int RedBlack<T>::updateHeight(BinNodePosi(T) x) {// �߶�Ϊ�ڸ߶�
	x->height = __max(stature(x->lc), stature(x->rc)); // ���ӵĺڸ߶�һ����ȣ����ǳ���˫��
	return IsBlack(x) ? x->height++; x->height;
}