#pragma once
template <typename T>
void travePost_R(BinNodePosi(T) x) {
	if (!x) return;
	travePost_R(x->lc);
	travePost_R(x->rc);
	printf("%d ", x->data);
}