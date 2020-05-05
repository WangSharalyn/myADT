#pragma once
template <typename T>
static Position(T) insertAt(const T& e, Position(T) x) {
	if (!x) x = new AVLNode<T>(e); // µÝ¹é»ù
	else if (e < x->data) {
		x->lc = insertAt(e, x->lc);
		if (stature(x->lc) - stature(x->rc) == 2) {
			if (e < x->lc->data)
				x = x->zig();
			else
				x = x->zig_zag();
		}
	}
	else if (x->data < e) {
		x->rc = insertAt(e, x->rc);
		if (stature(x->rc) - stature(x->lc) == 2) {
			if (x->rc->data < e)
				x = x->zag();
			else
				x = x->zag_zig();
		}
	}
	x->height = _max(stature(x->lc), stature(x->rc))+1;
	return x;
}

template <typename T>
Position(T) AVLT<T>::insert(const T& e) {
	return _root = insertAt(e, _root);
}