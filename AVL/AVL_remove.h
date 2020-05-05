#pragma once
template <typename T>
bool AVL<T>::remove(const T& e) {
	BinNodePosi(T)& x = this->search(e);
	if (!x) return false; // ȷ��Ŀ�����
	removeAt(x, this->_hot); this->_size--; // �Ȱ���BST����ɾ�����˺�ԭ�ڵ�֮��_hot�������Ⱦ�����ʧ��
	for (BinNodePosi(T) g = this->_hot; g; g = g->parent) {
		if(!AvlBanced(*g))
			g = ((g->parent == nullptr) ? this->_root : (g->parent->lc == g ? g->parent->lc : g->parent->rc)) = this->rotateAt(tallerChild(tallerChild(g)));
		this->updateHeight(g);
	}
	return true;
}