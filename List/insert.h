#pragma once
// 插入末节点，首节点，前驱和后继

template <typename T>
ListNodePosi(T) List<T>::insertAsFirst(const T& e) {// 插入首节点
	ListNodePosi(T) p = new listNode<T>(e);
	p->succ = header->succ;
	header->succ->pred = p;
	header->succ = p;
	_size++;
	return p;
}

template <typename T>
ListNodePosi(T) List<T>::insertAsLast(const T& e) {// 插入末节点
	ListNodePosi(T) p = new listNode<T>(e);
	p->succ = trailer;
	p->pred = trailer->pred;
	trailer->pred->succ = p;
	trailer->pred = p;
	_size++;
	return p;
}

template <typename T>
ListNodePosi(T) List<T>::insertA(ListNodePosi(T) p, const T& e) {// 在节点p之后插入节点
	ListNodePosi(T) n = new listNode<T>(e);
	n->succ = p->succ;
	n->pred = p;
	p->succ->pred = n;
	p->succ = n;
	_size++;
	return n;
}

template <typename T>
ListNodePosi(T) List<T>::insertB(ListNodePosi(T) p, const T& e) {// 在节点p之前插入节点
	ListNodePosi(T) n = new listNode<T>(e);
	n->succ = p;
	n->pred = p->pred;
	p->pred->succ = n;
	p->pred = n;
	_size++;
	return n;
}