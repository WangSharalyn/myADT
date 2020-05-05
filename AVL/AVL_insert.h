#pragma once
template <typename T>
BinNodePosi(T) AVL<T>::insert(const T& e) {
	BinNodePosi(T)& x = this->search(e);
	if (x) return x;// 若目标已存在
	BinNodePosi(T) xx = x = new BinNode<T>(e, this->_hot); this->_size++; // 创建新节点
// x 的父亲 _hot 若增高， 则其祖父可能失衡
	for (BinNodePosi(T) g = this->_hot; g; g = g->parent) {// 从x之父出发向上，逐层检测各代祖先g
		if (!AvlBanced(*g)) {// 一旦发现g出现失衡
			((g->parent == nullptr) ? this->_root : (g->parent->lc == g ? g->parent->lc : g->parent->rc)) = this->rotateAt(tallerChild(tallerChild(g)));
			break;
		}
		else
			this->updateHeight(g);
	}
	return xx;
}