#pragma once
// ɾ����x�ڵ�Ϊ�������������ظ�����ԭ�ȵĹ�ģ
template <typename T>
int BinTree<T>::remove(BinNodePosi(T) x) {
	if (!(x->parent)) _root = nullptr;
	else if (x == x->parent->lc) x->parent->lc = nullptr;
	else if (x == x->parent->rc) x->parent->rc = nullptr;
	int n = removeAt(x);
	_size -= n;
	return n;
}

template <typename T>
static int removeAt(BinNodePosi(T) x) {
	if (!x) return 0;
	int n = 1 + removeAt(x->lc) + removeAt(x->rc);
	delete x;
	return n;
}