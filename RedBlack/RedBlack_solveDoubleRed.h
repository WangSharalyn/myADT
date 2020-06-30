#pragma once

/*********************************************************
* RedBlack ˫������㷨������ڵ�x���丸��Ϊ��ɫ�����⡣��Ϊ������
*   RR-1: 2����ɫ��ת��2�κڸ߶ȸ��£�1~2����ת�����ٵݹ�
*   RR-2: 3����ɫ��ת��3�κڸ߶ȸ��£�0����ת����Ҫ�ݹ�
*********************************************************/
template <typename T>
void RedBlack<T>::solveDoubleRed(BinNodePosi(T) x) {
	if (!x->parent) {// ���ѵݹ�ת������������ת�ڣ������ĺڸ߶�Ҳ��֮����
		this->_root->color = RB_BLACK;
		this->_root->height++;
		return;
	}
	BinNodePosi(T) p = x->parent; if (IsBlack(p)) return; // ��pΪ�ڣ������ֹ����
	BinNodePosi(T) g = p->parent; // pΪ�죬��x���游�ش��ڣ��ұ�Ϊ��ɫ
	BinNodePosi(T) u = (p == g->lc) ? g->rc : g->lc;
	if (IsBlack(u)) {// uΪ��ɫ�� RR-1
		if (IsLChild(x) == IsLChild(p)) // x��p��ͬ�࣬zig-zig��zag-zag
			p->color = RB_BLACK; // p�ɺ�ת��
		else
			x->color = RB_BLACK; // x�ɺ�ת�ڣ�x��p����࣬zig-zag��zag-zig
		g->color = RB_RED; // g�ɺ�ת��
		BinNodePosi(T) gg = g->parent; // ���游
		BinNodePosi(T) r = (gg ? this->_root: (IsLChild(g)? gg->lc:gg->rc)) = this->rotateAt(x);
		r->parent = gg;
	}
	else {// uΪ��ɫ RR-2
		p->color = RB_BLACK; p->height++;// p�ɺ�ת��
		u->color = RB_BLACK; u->height++; // u�ɺ�ת��
		if (g->parent) g->color = RB_RED; // g���Ǹ�����ת��
		solveDoubleRed(g);
	}
}