#pragma once
#include "BinNode_travPre_R.h"
#include "BinNode_travPre_I1.h"
template <typename T>
void BinNode<T>::travPre() {
	switch (rand() % 2) {
	case 1: travePre_R(this); break;
	default: travPre_I1(this); break;
	}
	putchar('\n');
}