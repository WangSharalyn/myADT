#include "BST.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	BST<int> bst;
	bst.insert(3);
	bst.insert(4);
	bst.insert(1);
	bst.insert(2);
	bst.insert(6);
	cout << bst.size() << endl;
	bst.traInorder_I();
	cout << endl;
	bst.remove(3);
	bst.traInorder_I();
	return 0;
}