#pragma once
template <typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot) {
	BinNodePosi(T) w = x; // 实际被摘除的节点
	BinNodePosi(T) succ = nullptr; // 实际被摘除节点的后继
	if (!x->lc)
		succ = x = x->rc; // 如果没有左子树，直接将x替换为x的右子树
	else if (!x->rc)
		succ = x = x->lc;
	else {// 若左子树和右子树都存在
		w = x->succ(); // 找到直接后继，直接后继必无左子树
		x->data = w->data;
		BinNodePosi(T) u = w->parent;
		((u == x) ? u->rc : u->lc) = succ = w->rc;
	}
	hot = w->parent;
	if (succ) succ->parent = hot;
	delete w;
	return succ;
}

template <typename T>
bool BST<T>::remove(const T& e) {
	BinNodePosi(T)& x = search(e);
	if (!x) return false;
	removeAt(x, _hot);
	this->updateHightAbove(_hot);
	return true;
}