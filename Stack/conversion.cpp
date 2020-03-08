#include "application.h"
// 实现十进制转换成base进制
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