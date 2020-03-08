#include "application.h"
// ∆•≈‰¿®∫≈
bool paren(const char* str, int lo, int hi) {
	Stack<char> S;
	for (int i = lo; i < hi; i++) {
		switch (str[i]) {
		case '(':
		case '[':
		case '{':
			S.push(str[i]);
			break;
		case ')':
			if (S.empty() || S.pop() != '(') return false; break;
		case ']':
			if (S.empty() || S.pop() != '[') return false; break;
		case '}':
			if (S.empty() || S.pop() != '{') return false; break;
		default:
			break;
		}
	}
	return S.empty();
}