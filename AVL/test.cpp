#include "AVL.h"

int main() {
	AVL<int> T;
	T.insert(20);
	T.insert(4);
	T.travLevel();
	T.insert(26);
	T.travLevel();
	T.insert(9);
	T.insert(3);
	T.travLevel();
	T.remove(26);
	T.travLevel();
	return 0;
}