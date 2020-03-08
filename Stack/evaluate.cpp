#include "application.h"
// ������׺���ʽ
float evaluate(char* str) {// ������׺���ʽ
	Stack<char> oper; // ��������
	Stack<float> opnd; // �������
	oper.push('\0');
	while (!oper.empty()) {
		if (isdigit(*str)) // �ж��Ƿ�Ϊ����
		{
			readNumber(str, opnd);
			cout << opnd.top() << ' ';
		}
		else {
			switch (orderBetween(oper.top(), *str)) {
				case '<':
					oper.push(*str);
					str++;
					break;
				case '=':
					oper.pop();
					str++;
					break;
				case '>': {
					char op = oper.pop();
					cout << op << ' ';
					if ('!' == op) {// һĿ�����
						float o1 = opnd.pop();
						opnd.push(operat(o1, op));
					}
					else {// ��Ŀ�����
						float o2 = opnd.pop();
						float o1 = opnd.pop();
						opnd.push(operat(o1, op, o2));
					}
					break;
				}
				default: exit(-1);
			}
		}
	}
	cout << endl;
	return opnd.pop();
}

void readNumber(char*& p, Stack<float>& stk) {// δ���Ǵ��ڸ��������
	stk.push(static_cast<float>(*p-'0'));
	while (isdigit(*(++p)))
		stk.push(stk.pop() * 10 + (*p)-'0');
	if ('.' != *p) return;// �˺��С���㣬����ζ�ŵ�ǰ���ֽ������
	float fraction = 1;// ������С������
	while (isdigit(*(++p)))
		stk.push(stk.pop() + (*p - '0') * (fraction /= 10));
}

char orderBetween(char c, char o) {
	return pri[optr2rank(c)][optr2rank(o)];
}

Operator optr2rank(char op) {
	switch (op) {
	case '+': return ADD;// ��
	case '-': return SUB;
	case '*': return MUL;
	case '/': return DIV;
	case '^': return POW;
	case '!': return FAC;
	case '(': return L_P;
	case ')': return R_P;
	case '\0': return EOE;
	default: exit(-1);
	}
}

float operat(float o1, char oper, float o2) { // ��Ŀ�����
	switch (oper) {
	case '+': return o1 + o2;
	case '-': return o1 - o2;
	case '*': return o1 * o2;
	case '/': if (0 == o2) exit(-1); return o1 / o2;
	case '^': return pow(o1, o2);
	default:exit(-1);
	}
}

float operat(float o, char oper) {
	switch (oper) {
	case '!': return 0.0; // �׳�
	default:exit(-1);
	}
}