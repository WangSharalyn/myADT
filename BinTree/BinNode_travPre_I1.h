#pragma once
#include "../Stack/Stack_list.h"
template <typename T>
void travPre_I1(BinNodePosi(T) x) {
	Stack<BinNodePosi(T)> S;
	while (x || !S.empty()) {
		while (x) {
			if (x->rc) S.push(x->rc);
			printf("%d ", x->data);
			x = x->lc;
		}
		if (!S.empty()) {
			x = S.pop();	
		}
	}
}