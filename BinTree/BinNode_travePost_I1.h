#pragma once
#include "../Stack/Stack_list.h"
template <typename T>
void travePost_I1(BinNodePosi(T) x) {
	Stack<BinNodePosi(T)> S;
	if (x) S.push(x);
	while (!S.empty()) {
		if (S.top() != x->parent) {// ��ջ���ǵ�ǰ�ڵ�֮�������Ϊ�����֣�
			while (BinNodePosi(T) s = S.top()){
				if (s->lc) {
					if (s->rc) S.push(s->rc);
					S.push(s->lc);
				}
				else {
					S.push(s->rc);
				}
			}
			S.pop(); // ����ջ���սڵ�
		}
		x = S.pop();
		printf("%d ", x->data);
	}
}