#pragma once
// ������������汾
template <typename T>
void BinNode<T>::traversalPreorder_I(BinNodePosi(T) x) {
	Stack<BinNodePosi(T)> S;
	while (x || !S.empty()) {
		while (x) {
			S.push(x->rc);
			std::cout << x->data << ' ';
			x = x->lc;
		}
		if (!S.empty()) {
			x = S.pop();
		}
	}
}