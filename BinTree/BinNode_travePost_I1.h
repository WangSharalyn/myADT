#pragma once
#include "../Stack/Stack_list.h"
template <typename T>
void travePost_I1(BinNodePosi(T) x) {
	Stack<BinNodePosi(T)> S;
	if (x) S.push(x);
	while (!S.empty()) {
		if (S.top() != x->parent) {// 若栈顶非当前节点之父（则必为其右兄）
			while (BinNodePosi(T) s = S.top()){
				if (s->lc) {
					if (s->rc) S.push(s->rc);
					S.push(s->lc);
				}
				else {
					S.push(s->rc);
				}
			}
			S.pop(); // 弹出栈顶空节点
		}
		x = S.pop();
		printf("%d ", x->data);
	}
}