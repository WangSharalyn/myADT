#pragma once
template <typename T>// �Ը�Ϊv��BST������e, ������
static BinNodePosi(T)& searchIn_I(BinNodePosi(T)& v, const T& e, BinNodePosi(T)& hot) {
	if (!(v) || (e == v->data)) return v;
	hot = v; // һ��������ȼ��µ�ǰ�ڵ�
	while (1) {
		BinNodePosi(T)& c = (e < hot->data) ? hot->lc : hot->rc;
		if (!(c) || (e == c->data)) return c;
		hot = c;
	}
}