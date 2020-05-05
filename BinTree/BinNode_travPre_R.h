#pragma once
template <typename T>
void travePre_R(BinNodePosi(T) x) {
	if (!x) return;
	printf("%d ", x->data);
	travePre_R(x->lc);
	travePre_R(x->rc);
}