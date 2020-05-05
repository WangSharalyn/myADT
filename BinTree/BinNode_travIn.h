#pragma once
#include "BinNode_travIn_R.h"
#include "BinNode_travIn_I1.h"
#include "BinNode_travIn_I2.h"
#include "BinNode_travIn_I3.h"
#include "BinNode_travIn_I4.h"
template <typename T>
void BinNode<T>::travIn() {
	switch (rand() % 4) {
	case 1:traveIn_R(this); break;
	case 2:travIn_I1(this); break;
	case 3:travIn_I2(this); break;
	default:travIn_I4(this); break;
	}
	putchar('\n');
}