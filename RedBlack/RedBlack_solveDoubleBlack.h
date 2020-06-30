#pragma once
/*****************************************************************
* RedBlack双黑调整算法：解决节点x与其替代的节点均为黑色的问题
*  分为三大类共四种情况：
*  BB-1: 2次颜色翻转，2次黑高度更新，1~2次旋转，不再递归 黑s有红子t
*  BB-2-R：2次颜色翻转，2次黑高度更新，0次旋转，不再递归 黑s无红子，p红
*  BB-2-B：1次颜色翻转，1次黑高度更新，0次旋转，需要递归 黑s无红子，p黑
*  BB-3：2次颜色翻转，2次黑高度更新，1次旋转，转为BB-1或BB-2-R 红s
*****************************************************************/
template <typename T>
void RedBlack<T>::solveDoubleBlack(BinNodePosi(T) r) {
	BinNodePosi(T) p = r ? r->parent : _hot; if (!p) return; // r的父亲
	BinNodePosi(T) s = (r == p->lc) ? p->rc : p->lc; // r的兄弟
	if (IsBlack(s)) {// 兄弟为黑色
		BinNodePosi(T) t = nullptr; // s的红孩子（若左右皆为红，左优先；皆黑时为空）
		if (IsRed(s->rc)) t = s->rc;
		if (IsRed(s->lc)) t = s->lc;
		if (t) {// 黑s有红子t BB-1
			RBColor oldColor = p->color; // 备份树根的颜色，将s染色
			BinNodePosi(T) b = (!p->parent) ? _root : (p->parent->lc == p ? p->parent->lc : p->parent->rc) = rotateAt(t);// 旋转
			if (b->lc) { b->lc->color = RB_BLACK; updateHeight(b->lc); }
			if (b->rc) { b->rc->color = RB_BLACK; updateHeight(b->rc); }
			b->color = oldColor; updateHeight(b);
		}
		else {// 无黑孩子
			s->color = RB_RED; s->height--;
			if (IsRed(p)) {// 黑s无红子，红p BB-2-R
				p->color = RB_BLACK;
			}
			else {// BB-2-B
				p->height--;
				solveDoubleBlack(p);
			}
		}
	}
	else {// s为红 BB-3
		s->color = RB_BLACK; p->color = RB_RED;
		BinNodePosi(T) t = (p->lc == s) ? s->lc : s->rc;// 取t与其父在同侧
		_hot = p; (!p->parent) ? _root : (p->parent->lc == p) ? p->parent->lc : p->parent->rc = rotateAt(t);
		solveDoubleBlack(r); 
	}
}