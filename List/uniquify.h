#pragma once
// �����б�ȥ��
template <typename T>
int List<T>::uniquify(){
	if (_size < 0) return 0;
	int oldSize = _size;
	ListNodePosi(T) low = first();
	ListNodePosi(T) fast = low->succ; // ������ָ�벻��д��ListNodePosi(T) low, fast, fast��ListNodePosi(T)����
	while (fast != trailer) {
		if (low->data == fast->data)
			remove(fast);
		else
			low = fast;
		fast = low->succ;
	}
	return oldSize - _size;
}