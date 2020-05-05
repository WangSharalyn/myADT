#pragma once

template <typename T>
inline bool IsLChild(BinNodePosi(T) x) {
	return (x->parent) && (x->parent->lc == x);
}

template <typename T>
inline bool IsRChild(BinNodePosi(T) x) {
	return (x->parent) && (x->parent->rc == x);
}

template <typename T>
BinNodePosi(T) BST<T>::rotateAt(BinNodePosi(T) v) {
	BinNodePosi(T) p = v->parent;
	BinNodePosi(T) g = p->parent;
 	if(IsLChild(p)) // zig
		if (IsLChild(v)) {// zig-zig
			p->parent = g->parent;
			return connect34(v, p, g, v->lc, v->rc, p->rc, g->rc);
		}
		else {// zig-zag
			v->parent = g->parent;
			return connect34(p, v, g, p->lc, v->lc, v->rc, g->rc);
		}
	else // zag
		if (IsRChild(p)) {// zag-zag
			p->parent = g->parent;
			return connect34(g, p, v, g->lc, p->lc, v->lc, v->rc);
		}
		else {// zag-zig
			v->parent = g->parent;
			return connect34(g, v, p, g->lc, v->lc, v->rc, p->rc);
		}
}