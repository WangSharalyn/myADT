#pragma once
template <typename T>
void List<T>::init() {
	header = new listNode<T>;
	trailer = new listNode<T>;
	header->succ = trailer;
	header->pred = nullptr;
	trailer->succ = nullptr;
	trailer->pred = header;
	_size = 0;
}