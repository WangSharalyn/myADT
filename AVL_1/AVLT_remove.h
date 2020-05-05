#pragma once
template <typename T>
static Position(T) removeAt(Position(T) x, const T& e) {
	if (!x) return x; // �����ڸýڵ�
	// ���ҽڵ�
	else if (e < x->data)
		x->lc = removeAt(x->lc, e);
	else if (e > x->data)
		x->rc = removeAt(x->rc, e);
	else {// �ҵ��ڵ�
		Position(T) w = x;
		if (!x->lc)
			x = x->rc;
		else if (!x->rc)
			x = x->lc;
		else {// ���Ӻ��Һ��Ӷ�����
			w = succ(x);
			x->data = w->data;
			x->rc = removeAt(x->data, x->rc);
		}
		delete w;
	}
	if (!x) return x;
	x->height = 1 + _max(stature(x->lc), stature(x->rc));
	if (stature(x->lc) - stature(x->rc) == 2)
		if (stature(x->lc->lc) - stature(x->lc->rc) == 1)
			return x->zig();
		else
			return x->zag_zig();
	else if (stature(x->rc) - stature(x->lc) == 2)
		if (stature(x->rc->rc) - stature(x->rc->lc) == 1)
			return x->zag();
		else
			return x->zig_zag();
	return x;
}

template <typename T>
bool AVLT<T>::remove(const T& e) {
	if (_root = removeAt(_root, e))
		return true;
	else
		return false;
}