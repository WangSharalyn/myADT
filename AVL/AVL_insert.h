#pragma once
template <typename T>
BinNodePosi(T) AVL<T>::insert(const T& e) {
	BinNodePosi(T)& x = this->search(e);
	if (x) return x;// ��Ŀ���Ѵ���
	BinNodePosi(T) xx = x = new BinNode<T>(e, this->_hot); this->_size++; // �����½ڵ�
// x �ĸ��� _hot �����ߣ� �����游����ʧ��
	for (BinNodePosi(T) g = this->_hot; g; g = g->parent) {// ��x֮���������ϣ�������������g
		if (!AvlBanced(*g)) {// һ������g����ʧ��
			((g->parent == nullptr) ? this->_root : (g->parent->lc == g ? g->parent->lc : g->parent->rc)) = this->rotateAt(tallerChild(tallerChild(g)));
			break;
		}
		else
			this->updateHeight(g);
	}
	return xx;
}