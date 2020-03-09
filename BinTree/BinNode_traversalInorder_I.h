#pragma once
// ÖÐÐò±éÀúµü´ú°æ
template <typename T>
void BinNode<T>::traversalInorder_I(BinNodePosi(T) x) {
	Stack<BinNodePosi(T)> S;
	while (x || !S.empty()) {
		while (x) {
			S.push(x);
			x = x->lc;
		}
		if (!S.empty()) {
			x = S.pop();
			std::cout << x->data << ' ';
			x = x->rc;
		}
	}
}