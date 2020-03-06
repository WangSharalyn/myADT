#pragma once
// ����ĩ�ڵ㣬�׽ڵ㣬ǰ���ͺ��

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(const T& e) {// �����׽ڵ�
	ListNodePosi(T) p = new listNode<T>(e);
	p->succ = header->succ;
	header->succ->pred = p;
	header->succ = p;
	_size++;
	return p;
}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(const T& e) {// ����ĩ�ڵ�
	ListNodePosi(T) p = new listNode<T>(e);
	p->succ = trailer;
	p->pred = trailer->pred;
	trailer->pred->succ = p;
	trailer->pred = p;
	_size++;
	return p;
}

template <typename T>
ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, const T& e) {// �ڽڵ�p֮�����ڵ�
	ListNodePosi(T) n = new listNode<T>(e);
	n->succ = p->succ;
	n->pred = p;
	p->succ->pred = n;
	p->succ = n;
	_size++;
	return n;
}

template <typename T>
ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, const T& e) {// �ڽڵ�p֮ǰ����ڵ�
	ListNodePosi(T) n = new listNode<T>(e);
	n->succ = p;
	n->pred = p->pred;
	p->pred->succ = n;
	p->pred = n;
	_size++;
	return n;
}