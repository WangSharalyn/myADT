#pragma once

template <typename T>
T List<T>::remove(ListNodePosi(T) p) {
	T temp = p->data; // ���ݴ�ɾ���ڵ����ֵ���ٶ�T���Ϳ�ֱ�Ӹ�ֵ
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	_size--;
	delete p;
	return temp;
}