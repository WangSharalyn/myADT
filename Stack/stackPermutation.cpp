#include "application.h"
// �ж��Ƿ�Ϊջ��ϴ֮һ
bool stackPermutation(int* a, int n, int* b) {// aΪ����ջ��ģΪn,bΪ���жϵ�ջ
	Stack<int> S; // ����ջ
	int i = 0; // ����ջa����
	for (int j = 0; j < n; j++) {
		while (S.empty() || S.top() != b[j])
			if (i < n)
				S.push(a[i++]);
			else
				return false;
		S.pop();
	}
	return true;
}