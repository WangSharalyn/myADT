#pragma once
// ���ظýڵ������Ĺ�ģ
template <typename T>
int BinNode<T>::size() {
	int s = 1;// ���뱾��
	if (lc) s += lc->size();
	if (rc) s += rc->size();
	return s;
}