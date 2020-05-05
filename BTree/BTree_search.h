#pragma once
template <typename T>
BTNodePosi(T) BTree<T>::search(const T& e) {
	BTNodePosi(T) v = _root;
	_hot = nullptr; // 从根节点出发
	while (v) {
		Rank r = v->key.search(e); // 在当前节点，找到不大于e的最大关键码
		if ((0 <= r) && (e == v->key[r])) return v;
		_hot = v;
		v = v->child[r + 1];// 转入对应子树，需要I/O，最费时间
	}// 此处借用的Vector的二分查找，但是通常可顺序查找
	return nullptr; // 失败到达外部节点
}