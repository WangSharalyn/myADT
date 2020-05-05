#pragma once
template <typename T>
static BinNodePosi(T)& searchIn_R(BinNodePosi(T)& v, const T& e, BinNodePosi(T)& hot) {
	if (!(v) || (e == v->data)) return v;
	hot = v;
	return searchIn_R(((e < hot->data) ? hot->lc : hot->rc), e, hot);
}