#pragma once
template <typename T>
BinNodePosi(T) BinNode<T>::succ() {
	BinNodePosi(T) s = this;
	if (rc) {// 若有右孩子，则后继为右孩子中最左的叶节点
		s = rc;
		while (s->lc) s = s->lc;
	}
	else {
		while (s->parent && s == s->parent->rc) s = s->parent;
		s = s->parent;
	}
	return s;
}