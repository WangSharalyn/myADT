#pragma once
template <typename T>
BTNodePosi(T) BTree<T>::search(const T& e) {
	BTNodePosi(T) v = _root;
	_hot = nullptr; // �Ӹ��ڵ����
	while (v) {
		Rank r = v->key.search(e); // �ڵ�ǰ�ڵ㣬�ҵ�������e�����ؼ���
		if ((0 <= r) && (e == v->key[r])) return v;
		_hot = v;
		v = v->child[r + 1];// ת���Ӧ��������ҪI/O�����ʱ��
	}// �˴����õ�Vector�Ķ��ֲ��ң�����ͨ����˳�����
	return nullptr; // ʧ�ܵ����ⲿ�ڵ�
}