#pragma once
template <typename T>
void travIn_I4(BinNodePosi(T) x) {
	while (true) {
		if (x->lc)
			x = x->lc;
		else {
			printf("%d ", x->data);
			while (!x->rc)//不断没有右分支
				if (!(x = x->succ())) return;
				else printf("%d ", x->data);
			x = x->rc;
		}
	}
}