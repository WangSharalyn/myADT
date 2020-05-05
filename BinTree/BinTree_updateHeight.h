#pragma once
template <typename T>
int BinTree<T>::updateHeight(BinNodePosi(T) x) {
	int hl = (x->lc) ? x->lc->height : -1;
	int hr = (x->rc) ? x->rc->height : -1;
	return x->height = 1 + ((hl > hr) ? hl : hr);
}

template <typename T>
void BinTree<T>::updateHightAbove(BinNodePosi(T) x) {
	while (x) {
		updateHeight(x);
		x = x->parent;
	}
}