#pragma once
template <typename T>
void travIn_I4(BinNodePosi(T) x) {
	while (true) {
		if (x->lc)
			x = x->lc;
		else {
			printf("%d ", x->data);
			while (!x->rc)//����û���ҷ�֧
				if (!(x = x->succ())) return;
				else printf("%d ", x->data);
			x = x->rc;
		}
	}
}