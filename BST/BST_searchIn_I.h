#pragma once
template <typename T>// 以根为v的BST中搜索e, 迭代版
static BinNodePosi(T)& searchIn_I(BinNodePosi(T)& v, const T& e, BinNodePosi(T)& hot) {
	if (!(v) || (e == v->data)) return v;
	hot = v; // 一般情况，先记下当前节点
	while (1) {
		BinNodePosi(T)& c = (e < hot->data) ? hot->lc : hot->rc;
		if (!(c) || (e == c->data)) return c;
		hot = c;
	}
}