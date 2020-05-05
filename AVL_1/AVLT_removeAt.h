#pragma once
template <typename T>
static int removeAt(Position(T) x) {
	if (!x) return 0;
	int n = 1 + removeAt(x->lc) + removeAt(x->rc);
	delete x;
	return n;
}

template <typename T>
int AVLT<T>::remove(Position(T) x) {
	return removeAt(_root);
}