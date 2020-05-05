#pragma once
template <typename T>
void BTree<T>::solveOverflow(BTNodePosi(T) v) {
	if (_order >= v->child.size()) return; // �ݹ��
	Rank s = _order / 2; // ��㣺�˴�Ӧ��_order = key.size() = child.size()-1
	BTNodePosi(T) u = new BTNode<T>(); // �½ڵ�����һ���պ���
	for (Rank j = 0; j < _order - s - 1; j++) { // v �Ҳ� _order-s-1�����Ӽ��ؼ������Ϊ�Ҳ�ڵ� u
		u->child.insert(v->child.remove(s + 1), j);
		u->key.insert(v->key.remove(s + 1), j);
	}
	u->child[_order - s - 1] = v->child.remove(s + 1); // �ƶ�v��ҵĺ���
	if (u->child[0])// ��u�ĺ��Ӳ�Ϊ��
		for (Rank j = 0; j < _order - s; j++)
			u->child[j]->parent = u; // ָ��u
	BTNodePosi(T) p = v->parent; // v ��ǰ�ĸ��ڵ�
	if (!p) { _root = p = new BTNode<T>(); p->child[0] = v; v->parent = p; }
	Rank r = 1 + p->key.search(v->key[0]);// p ��ָ��u��ָ�����
	p->key.insert(v->key.remove(s), r);
	p->child.insert(u, r + 1);
	u->parent = p;
	solveOverflow(p);
}