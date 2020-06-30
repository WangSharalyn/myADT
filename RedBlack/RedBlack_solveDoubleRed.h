#pragma once

/*********************************************************
* RedBlack 双红调整算法：解决节点x与其父都为红色的问题。分为两大类
*   RR-1: 2次颜色翻转，2次黑高度更新，1~2次旋转，不再递归
*   RR-2: 3次颜色翻转，3次黑高度更新，0次旋转，需要递归
*********************************************************/
template <typename T>
void RedBlack<T>::solveDoubleRed(BinNodePosi(T) x) {
	if (!x->parent) {// 若已递归转至树根，将其转黑，整树的黑高度也随之递增
		this->_root->color = RB_BLACK;
		this->_root->height++;
		return;
	}
	BinNodePosi(T) p = x->parent; if (IsBlack(p)) return; // 若p为黑，则可终止调整
	BinNodePosi(T) g = p->parent; // p为红，则x的祖父必存在，且必为黑色
	BinNodePosi(T) u = (p == g->lc) ? g->rc : g->lc;
	if (IsBlack(u)) {// u为黑色， RR-1
		if (IsLChild(x) == IsLChild(p)) // x和p在同侧，zig-zig或zag-zag
			p->color = RB_BLACK; // p由红转黑
		else
			x->color = RB_BLACK; // x由红转黑，x和p在异侧，zig-zag或zag-zig
		g->color = RB_RED; // g由黑转红
		BinNodePosi(T) gg = g->parent; // 曾祖父
		BinNodePosi(T) r = (gg ? this->_root: (IsLChild(g)? gg->lc:gg->rc)) = this->rotateAt(x);
		r->parent = gg;
	}
	else {// u为红色 RR-2
		p->color = RB_BLACK; p->height++;// p由红转黑
		u->color = RB_BLACK; u->height++; // u由红转黑
		if (g->parent) g->color = RB_RED; // g若非根，则转红
		solveDoubleRed(g);
	}
}