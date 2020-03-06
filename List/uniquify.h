#pragma once
// 有序列表去重
template <typename T>
int List<T>::uniquify(){
	if (_size < 0) return 0;
	int oldSize = _size;
	ListNodePosi(T) low = first();
	ListNodePosi(T) fast = low->succ; // 定义宏的指针不能写成ListNodePosi(T) low, fast, fast是ListNodePosi(T)类型
	while (fast != trailer) {
		if (low->data == fast->data)
			remove(fast);
		else
			low = fast;
		fast = low->succ;
	}
	return oldSize - _size;
}