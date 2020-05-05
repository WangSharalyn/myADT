#pragma once
#include "../Stack/Stack_list.h"
template <typename T>
void travIn_I1(BinNodePosi(T) x) {
	Stack<BinNodePosi(T)> S;
	while (x || !S.empty()) {
		while (x) {
			S.push(x);
			x = x->lc;
		}
		if (!S.empty()) {
			x = S.pop();
			printf("%d ", x->data);
			x = x->rc;
		}
	}
}