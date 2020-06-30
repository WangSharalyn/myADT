#pragma once
/*****************************************************************
* RedBlack˫�ڵ����㷨������ڵ�x��������Ľڵ��Ϊ��ɫ������
*  ��Ϊ�����๲���������
*  BB-1: 2����ɫ��ת��2�κڸ߶ȸ��£�1~2����ת�����ٵݹ� ��s�к���t
*  BB-2-R��2����ɫ��ת��2�κڸ߶ȸ��£�0����ת�����ٵݹ� ��s�޺��ӣ�p��
*  BB-2-B��1����ɫ��ת��1�κڸ߶ȸ��£�0����ת����Ҫ�ݹ� ��s�޺��ӣ�p��
*  BB-3��2����ɫ��ת��2�κڸ߶ȸ��£�1����ת��תΪBB-1��BB-2-R ��s
*****************************************************************/
template <typename T>
void RedBlack<T>::solveDoubleBlack(BinNodePosi(T) r) {
	BinNodePosi(T) p = r ? r->parent : _hot; if (!p) return; // r�ĸ���
	BinNodePosi(T) s = (r == p->lc) ? p->rc : p->lc; // r���ֵ�
	if (IsBlack(s)) {// �ֵ�Ϊ��ɫ
		BinNodePosi(T) t = nullptr; // s�ĺ캢�ӣ������ҽ�Ϊ�죬�����ȣ��Ժ�ʱΪ�գ�
		if (IsRed(s->rc)) t = s->rc;
		if (IsRed(s->lc)) t = s->lc;
		if (t) {// ��s�к���t BB-1
			RBColor oldColor = p->color; // ������������ɫ����sȾɫ
			BinNodePosi(T) b = (!p->parent) ? _root : (p->parent->lc == p ? p->parent->lc : p->parent->rc) = rotateAt(t);// ��ת
			if (b->lc) { b->lc->color = RB_BLACK; updateHeight(b->lc); }
			if (b->rc) { b->rc->color = RB_BLACK; updateHeight(b->rc); }
			b->color = oldColor; updateHeight(b);
		}
		else {// �޺ں���
			s->color = RB_RED; s->height--;
			if (IsRed(p)) {// ��s�޺��ӣ���p BB-2-R
				p->color = RB_BLACK;
			}
			else {// BB-2-B
				p->height--;
				solveDoubleBlack(p);
			}
		}
	}
	else {// sΪ�� BB-3
		s->color = RB_BLACK; p->color = RB_RED;
		BinNodePosi(T) t = (p->lc == s) ? s->lc : s->rc;// ȡt���丸��ͬ��
		_hot = p; (!p->parent) ? _root : (p->parent->lc == p) ? p->parent->lc : p->parent->rc = rotateAt(t);
		solveDoubleBlack(r); 
	}
}