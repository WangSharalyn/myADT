#pragma once

template <typename T>
T List<T>::remove(ListNodePosi(T) p) {
	T temp = p->data; // 备份待删除节点的数值，假定T类型可直接赋值
	p->pred->succ = p->succ;
	p->succ->pred = p->pred;
	_size--;
	delete p;
	return temp;
}