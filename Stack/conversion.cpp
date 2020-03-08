#include "application.h"
// ʵ��ʮ����ת����base����
void conversion(__int64 a, int base) {
	char digit[] = "0123456789ABCDEF";
	Stack<char> S;
	while (a > 0) {
		S.push(digit[a % base]);
		a /= base;
	}
	while (!S.empty())
		cout << S.pop();
	cout << endl;
}