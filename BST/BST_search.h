#pragma once
// 查找
template <typename T>
BinNodePosi(T)& BST<T>::search(const T& e) {
	return search_I(this->_root, e, _hot = nullptr);// _hot要置零
}

template <typename T>
static BinNodePosi(T)& search_I(BinNodePosi(T)& x, const T& e, BinNodePosi(T)& hot) {// 迭代版本
	if ((!x) || (e == x->data)) return x;
	hot = x;
	while (1) {
		BinNodePosi(T)& c = (e < hot->data) ? (hot->lc) : (hot->rc);
		if ((!c) || (e == c->data))
			return c;
		hot = c;
	}
}

template <typename T>
static BinNodePosi(T)& search_R(BinNodePosi(T)& x, const T& e, BinNodePosi(T)& hot) {// 递归版本
	if ((!x) || (e == x->data)) return x;
	hot = x;
	return search_R(((e < x->data) ? x->lc : x->rc), e, hot);
}