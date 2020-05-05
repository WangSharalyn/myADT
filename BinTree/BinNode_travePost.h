#pragma once
#include "BinNode_travePost_R.h"
#include "BinNode_travePost_I1.h"
template <typename T>
void BinNode<T>::travPost() {
	switch (rand() % 2) {
	case 1: travePost_R(this); break;
	default:travePost_I1(this); break;
	}
	putchar('\n');
}