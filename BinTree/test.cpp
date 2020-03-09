#include "BinNode.h"
#include <iostream>

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
	return 0;
}