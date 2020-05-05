#include "BST.h"

int main() {
	BST<int> T;
	T.insert(5);
	T.insert(2);
	auto x = T.insert(6);
	T.insert(7);
	T.insert(4);
	T.travIn();
	T.remove(5);
	T.travIn();
	return 0;
}