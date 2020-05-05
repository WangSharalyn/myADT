#pragma once
template <typename T>
void traveIn_R(BinNodePosi(T) x) {
	if (!x) return;
	traveIn_R(x->lc);
	printf("%d ", x->data);
	traveIn_R(x->rc);
}