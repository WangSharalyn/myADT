#pragma once
template <typename T>
void travIn_I3(BinNodePosi(T) x) {// �����汾3�����踨��ջ
	bool backtrack = false; // ǰһ���Ƿ�����������ݡ�������ʡȥջ����O��1�������ռ�
	while (true) {
		if (!backtrack && x->lc) // �����������Ҳ��Ǹոջ��ݣ�������������
			x = x->lc;
		else {// ��������������ոջ���
			printf("%d ", x->data);// ���ʽڵ�
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