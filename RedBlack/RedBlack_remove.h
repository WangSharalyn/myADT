#pragma once
#define BlackHeightUpdated(x) ( /*RedBlack�߶ȸ�������*/ \
   ( stature( (x).lc ) == stature( (x).rc ) ) && \
   ( (x).height == ( IsRed(& x) ? stature( (x).lc ) : stature( (x).lc ) + 1 ) ) \
)
template <typename T>
bool RedBlack<T>::remove(const T& e) {
	BinNodePosi(T)& x = search(e);
	if (!x) return false; // ��������
	BinNodePosi(T) r = removeAt(x, this->_hot); if (!(--_size)) return true; // ɾ��
	if (!_hot) {// ���ձ�ɾ�����Ǹ��ڵ㣬����Ⱦ�ڣ������¸߶�
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