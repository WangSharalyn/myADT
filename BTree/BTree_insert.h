#pragma once
template <typename T>
bool BTree<T>::insert(const T& e) {
	BTNodePosi(T) v = search(e); if (v) return false; // 目标节点已存在
	Rank r = _hot->key.search(e); // 在_hot的有序关键码中查找合适的插入位置
	_hot->key.insert(e, r + 1);
	_hot->child.insert(nullptr, r + 2);
	_size++; // 更新规模
	solveOverflow(_hot); // 如有需要，需做分裂
	return true;
}