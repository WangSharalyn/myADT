#include <iostream>
#include "List.h"
using std::cout;
using std::endl;

int main() {
	List<int> l;
	l.insertAsLast(1);
	l.insertAsLast(5);
	l.insertAsLast(4);
	l.insertAsLast(3);
	l.printL();
	//l.selectionSort();
	l.insertionSort();
	l.printL();
	//cout << l.deduplicate() << endl;
	cout << l.uniquify() << endl;
	l.printL();
	ListNodePosi(int) n = l.find(1);
	ListNodePosi(int) n1 = l.search(3);
	cout << n1->data << endl; // 2
	cout << n->succ->data << endl;//2
	cout << l.size() << endl;// 3
	cout << l[2] << endl; // 4
	cout << l.selectMax()->data << endl; // 4
	return 0;
}