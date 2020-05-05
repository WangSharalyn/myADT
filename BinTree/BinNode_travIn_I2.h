#pragma once
#include "../Stack/Stack_list.h"
template <typename T>
void travIn_I2(BinNodePosi(T) x) {
	Stack<BinNodePosi(T)> S;
	while (true) {
		if (x) {
			S.push(x);
			x = x->lc;
		}
		else if (!S.empty()) {
			x = S.pop();
			printf("%d ", x->data);
			x = x->rc;
		}
		else
			break;
	}
}