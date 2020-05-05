#pragma once
template <typename T>
void BTree<T>::solveOverflow(BTNodePosi(T) v) {
	if (_order >= v->child.size()) return; // 递归基
	Rank s = _order / 2; // 轴点：此处应有_order = key.size() = child.size()-1
	BTNodePosi(T) u = new BTNode<T>(); // 新节点已有一个空孩子
	for (Rank j = 0; j < _order - s - 1; j++) { // v 右侧 _order-s-1个孩子及关键码分裂为右侧节点 u
		u->child.insert(v->child.remove(s + 1), j);
		u->key.insert(v->key.remove(s + 1), j);
	}
	u->child[_order - s - 1] = v->child.remove(s + 1); // 移动v最靠右的孩子
	if (u->child[0])// 若u的孩子不为空
		for (Rank j = 0; j < _order - s; j++)
			u->child[j]->parent = u; // 指向u
	BTNodePosi(T) p = v->parent; // v 当前的父节点
	if (!p) { _root = p = new BTNode<T>(); p->child[0] = v; v->parent = p; }
	Rank r = 1 + p->key.search(v->key[0]);// p 中指向u的指针的秩
	p->key.insert(v->key.remove(s), r);
	p->child.insert(u, r + 1);
	u->parent = p;
	solveOverflow(p);
}