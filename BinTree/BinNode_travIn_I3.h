#pragma once
template <typename T>
void travIn_I3(BinNodePosi(T) x) {// 迭代版本3，无需辅助栈
	bool backtrack = false; // 前一步是否从左子树回溯————省去栈，仅O（1）辅助空间
	while (true) {
		if (!backtrack && x->lc) // 若有左子树且不是刚刚回溯，则深入左子树
			x = x->lc;
		else {// 否则无左子树或刚刚回溯
			printf("%d ", x->data);// 访问节点
			if (x->rc) {
				x = x->rc;
				backtrack = false;
			}
			else {
				if (!(x = x->succ())) break;
				backtrack = true;
			}
		}
	}
}