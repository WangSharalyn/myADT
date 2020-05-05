#pragma once
template <typename T>
bool BTree<T>::remove(const T& e) {
	BTNodePosi(T) v = search(e); if (!v) return false; // ȷ�Ͻڵ����
	Rank r = v->key.search(e);
	if (v->child[0]) {// �� v ��Ҷ�ӽڵ㣬�� e �ĺ�̱�����ĳҶ�ӽڵ�
		BTNodePosi(T) u = v->child[r + 1];// ����������һֱ����
		while (u->child[0]) u = u->child[0];
		v->key[r] = u->key[0]; v = u; r = 0;
	}
	v->key.remove(r); v->child.remove(r + 1); _size--;
	solveUnderflow(v);
	return true;
}