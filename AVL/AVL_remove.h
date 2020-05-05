#pragma once
template <typename T>
bool AVL<T>::remove(const T& e) {
	BinNodePosi(T)& x = this->search(e);
	if (!x) return false; // 确认目标存在
	removeAt(x, this->_hot); this->_size--; // 先按照BST规则删除，此后，原节点之父_hot及其祖先均可能失衡
	for (BinNodePosi(T) g = this->_hot; g; g = g->parent) {
		if(!AvlBanced(*g))
			g = ((g->parent == nullptr) ? this->_root : (g->parent->lc == g ? g->parent->lc : g->parent->rc)) = this->rotateAt(tallerChild(tallerChild(g)));
		this->updateHeight(g);
	}
	return true;
}