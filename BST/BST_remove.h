#pragma once
template <typename T>
static BinNodePosi(T) removeAt(BinNodePosi(T)& x, BinNodePosi(T)& hot) {
	BinNodePosi(T) w = x; // ʵ�ʱ�ժ���Ľڵ�
	BinNodePosi(T) succ = nullptr; // ʵ�ʱ�ժ���ڵ�ĺ��
	if (!x->lc)
		succ = x = x->rc; // ���û����������ֱ�ӽ�x�滻Ϊx��������
	else if (!x->rc)
		succ = x = x->lc;
	else {// ����������������������
		w = x->succ(); // �ҵ�ֱ�Ӻ�̣�ֱ�Ӻ�̱���������
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