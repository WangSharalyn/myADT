#pragma once
// 删除某一节点，适用于AVL, Splay, RedBlack等BST
// x在此之前经查找定位，并确认非空指针，故删除必成功；与search_I不同，
// 调用之前*******不用将_hot置零*******，返回值指向实际被删除节点的接替者，
// hot指向实际被删除节点的父亲————二者均有可能为nullptr。
template <typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot) {
	BinNodePosi(T) w = x;// 实际被摘除的节点
	BinNodePosi(T) succ = nullptr; // 实际被删除节点的后继
	if (!(x->lc))
		succ = x = x->rc; // 左子树为空，直接将x替换为右子树
	else if (!(x->rc))
		succ = x = x->lc; // 右子树为空，直接将x替换为左子树
	else {// 既存在左子树，又存在右子树
		w = w->succ();// 找到直接后继
		x->data = w->data;// 交换数据
		BinNodePosi(T) u = w->parent;
		((u == x) ? u->rc : u->lc) = succ = w->rc;
	}
	hot = w->parent;
	if (succ) succ->parent = hot;
	delete w;
	return succ;
}

template <typename T>
void swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = temp;
}

template <typename T>
bool BST<T>::remove(const T& e) {
	BinNodePosi(T)& x = search(e);
	if (!x) return false;
	removeAt(x, _hot);
	this->_size--;
	this->updateHeightAbove(_hot);
	return true;
}