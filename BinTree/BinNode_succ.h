#pragma once
// �ڵ���������е�ֱ�Ӻ��
template <typename T>
BinNodePosi(T) BinNode<T>::succ() {
	BinNodePosi(T) s = this;
	if (rc) {
		s = rc;
		while ((s) && (s->lc))
			s = s->lc;
	}
	else {
		while (s && (s->rc)) s = s->parent;
		s = s->parent;
	}
	return s;
}