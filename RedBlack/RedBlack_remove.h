#pragma once
#define BlackHeightUpdated(x) ( /*RedBlack高度更新条件*/ \
   ( stature( (x).lc ) == stature( (x).rc ) ) && \
   ( (x).height == ( IsRed(& x) ? stature( (x).lc ) : stature( (x).lc ) + 1 ) ) \
)
template <typename T>
bool RedBlack<T>::remove(const T& e) {
	BinNodePosi(T)& x = search(e);
	if (!x) return false; // 若不存在
	BinNodePosi(T) r = removeAt(x, this->_hot); if (!(--_size)) return true; // 删除
	if (!_hot) {// 若刚被删除的是根节点，则将其染黑，并更新高度
		_root->color = RB_BLACK;
		updateHeight(_root);
		return true;
	}
	if (BlackHeightUpdated(*__hot)) return true;
	if (IsRed(r)) {
		r->color = RB_BLACK; r->height++; return true;
	}
	solveDoubleBlack(r); return true;
}