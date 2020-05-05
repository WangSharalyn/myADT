#include "BTree.h"

int main() {
	BTree<int> T;
	T.insert(53);
	T.insert(36);
	T.insert(77);
	T.insert(89);
	T.insert(19);
	T.insert(41);
	T.remove(19);
	return 0;
}