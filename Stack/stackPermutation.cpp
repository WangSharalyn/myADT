#include "application.h"
// 判断是否为栈混洗之一
bool stackPermutation(int* a, int n, int* b) {// a为输入栈规模为n,b为待判断的栈
	Stack<int> S; // 辅助栈
	int i = 0; // 输入栈a的秩
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