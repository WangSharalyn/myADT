#pragma once
template <typename T>
static Position(T)& search_I(Position(T) x, const T& e, Position(T)& hot) {
	if (!x || x->data == e) return x;
	hot = x;
	while (1) {
		Position(T)& c = (e < hot->data) ? hot->lc : hot->rc;
		if (!c || c->data == e) return c;
		hot = c;
	}
}

template <typename T>
Position(T)& AVLT<T>::search(const T& e) {
	return search_I(_root, e, _hot);
}