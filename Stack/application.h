#pragma once
#include "Stack_vector.h"
#include "priority.h"
#include <iostream>
#include <ctype.h>
#include <cmath>
using std::cout;
using std::endl;
// 栈的应用

// 进制转换
void conversion(__int64 a, int base);

// 栈混洗
bool stackPermutation(int*, int, int*);

// 括号匹配
bool paren(const char* str, int lo, int hi);

// 中缀表达式
float evaluate(char* str);
void readNumber(char*& p, Stack<float>& stk);
char orderBetween(char c, char o);
float operat(float o1, char oper, float o2);// 二目运算符
float operat(float o, char oper); // 一目运算符
Operator optr2rank(char op);

// 逆波兰表达式
void rpn(char* str);