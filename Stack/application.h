#pragma once
#include "Stack_vector.h"
#include "priority.h"
#include <iostream>
#include <ctype.h>
#include <cmath>
using std::cout;
using std::endl;
// ջ��Ӧ��

// ����ת��
void conversion(__int64 a, int base);

// ջ��ϴ
bool stackPermutation(int*, int, int*);

// ����ƥ��
bool paren(const char* str, int lo, int hi);

// ��׺���ʽ
float evaluate(char* str);
void readNumber(char*& p, Stack<float>& stk);
char orderBetween(char c, char o);
float operat(float o1, char oper, float o2);// ��Ŀ�����
float operat(float o, char oper); // һĿ�����
Operator optr2rank(char op);

// �沨�����ʽ
void rpn(char* str);