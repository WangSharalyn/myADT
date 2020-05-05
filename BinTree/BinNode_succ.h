#pragma once
template <typename T>
BinNodePosi(T) BinNode<T>::succ() {
	BinNodePosi(T) s = this;
	if (rc) {// �����Һ��ӣ�����Ϊ�Һ����������Ҷ�ڵ�
		s = rc;
		while (s->lc) s = s->lc;
	}
	else {
		while (s->parent && s == s->parent->rc) s = s->parent;
		s = s->parent;
	}
	return s;
}