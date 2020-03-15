#include "BinTree.h"
#include <iostream>
using std::cout;
using std::endl;

int main() {
	BinNode<int> a(1);
	BinNodePosi(int) b = a.insertAsLc(3);
	b->insertAsLc(4);
	b->insertAsRc(2);
	a.traversalPreorder_R(&a);
	std::cout << std::endl;
	a.traversalPreorder_I(&a);
	std::cout << std::endl;
	a.traversalInorder_R(&a);
	std::cout << std::endl;
	a.traversalInorder_I(&a);
	std::cout << std::endl;
	a.traversalPostorder_R(&a);
	std::cout << std::endl;
	a.traversalPostorder_I(&a);
	std::cout << std::endl;
	a.traversalLevel(&a);
	std::cout << std::endl;
	BinTree<int> bt;
	cout << bt.size() << endl;
	cout << bt.empty() << endl;
	BinNodePosi(int) root = bt.insertAsRoot(1);
	BinNodePosi(int) temp = bt.insertAsLC(root, 2);
	cout << bt.size() << endl;
	cout << bt.size(root) << endl;
	return 0;
}