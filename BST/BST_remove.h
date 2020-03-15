#pragma once
// ɾ��ĳһ�ڵ㣬������AVL, Splay, RedBlack��BST
// x�ڴ�֮ǰ�����Ҷ�λ����ȷ�Ϸǿ�ָ�룬��ɾ���سɹ�����search_I��ͬ��
// ����֮ǰ*******���ý�_hot����*******������ֵָ��ʵ�ʱ�ɾ���ڵ�Ľ����ߣ�
// hotָ��ʵ�ʱ�ɾ���ڵ�ĸ��ס����������߾��п���Ϊnullptr��
template <typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot) {
	BinNodePosi(T) w = x;// ʵ�ʱ�ժ���Ľڵ�
	BinNodePosi(T) succ = nullptr; // ʵ�ʱ�ɾ���ڵ�ĺ��
	if (!(x->lc))
		succ = x = x->rc; // ������Ϊ�գ�ֱ�ӽ�x�滻Ϊ������
	else if (!(x->rc))
		succ = x = x->lc; // ������Ϊ�գ�ֱ�ӽ�x�滻Ϊ������
	else {// �ȴ������������ִ���������
		w = w->succ();// �ҵ�ֱ�Ӻ��
		x->data = w->data;// ��������
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