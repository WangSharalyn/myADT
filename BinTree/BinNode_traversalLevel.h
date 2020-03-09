#pragma once
// ≤„–Ú±È¿˙
template <typename T>
void BinNode<T>::traversalLevel(BinNodePosi(T) x) {
	if (!x) return;
	Queue<BinNodePosi(T)> q;
	q.enqueue(x);
	while (q.size()) {
		x = q.dequeue();
		std::cout << x->data << ' ';
		if (x->lc) q.enqueue(x->lc);
		if (x->rc) q.enqueue(x->rc);
	}
}