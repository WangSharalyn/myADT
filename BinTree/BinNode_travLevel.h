#pragma once
#include "../Queue/Queue_list.h"
template <typename T>
void BinNode<T>::travLevel() {
	Queue<BinNodePosi(T)> Q;
	Q.enqueue(this);
	while (!Q.empty()) {
		BinNodePosi(T) node = Q.dequeue();
		printf("%d ", node->data);
		if (node->lc) Q.enqueue(node->lc);
		if (node->rc) Q.enqueue(node->rc);
	}
	putchar('\n');
}