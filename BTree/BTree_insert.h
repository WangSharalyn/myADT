#pragma once
template <typename T>
bool BTree<T>::insert(const T& e) {
	BTNodePosi(T) v = search(e); if (v) return false; // Ŀ��ڵ��Ѵ���
	Rank r = _hot->key.search(e); // ��_hot������ؼ����в��Һ��ʵĲ���λ��
	_hot->key.insert(e, r + 1);
	_hot->child.insert(nullptr, r + 2);
	_size++; // ���¹�ģ
	solveOverflow(_hot); // ������Ҫ����������
	return true;
}