#include "BinTree.h"
#include <iostream>
using namespace std;

int main() {
	BinNodePosi(int) root = new BinNode<int>(1); //   1
	root->insertAsLC(2);                         //  2  3
	root->insertAsRC(3);                         //    4
	root->rc->insertAsLC(4);
	cout << root->size() << endl;
	root->travLevel();
	root->travPre();
	root->travIn();
	root->travPost();
	//root->zig();
	//root->travLevel();
	BinTree<int> T;
	T.insertAsRoot(1);
	return 0;
}