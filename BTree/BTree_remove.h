#pragma once
template <typename T>
bool BTree<T>::remove(const T& e) {
	BTNodePosi(T) v = search(e); if (!v) return false; // 确认节点存在
	Rank r = v->key.search(e);
	if (v->child[0]) {// 若 v 非叶子节点，则 e 的后继必属于某叶子节点
		BTNodePosi(T) u = v->child[r + 1];// 在右子树中一直向左
		while (u->child[0]) u = u->child[0];
		v->key[r] = u->key[0]; v = u; r = 0;
	}
	v->key.remove(r); v->child.remove(r + 1); _size--;
	solveUnderflow(v);
	return true;
}