#pragma once
template <typename T>
Position(T) succ(Position(T) x) {
	if (!x || !_root) return nullptr;
	Position(T) s = x;
	Position(T) r = _root;
	if (x->rc) {
		s = x->rc;
		while (s->lc) s = s->lc;
	}
	else {
		while (r != x) {
			if (r->data < x->data)
				r = r->rc;
			else {
				s = r;
				r = r->lc;
			}
		}
	}
	return s;
}