#include "AVLT.h"

int main() {
	AVLT<int> T;
	T.insert(20);
	T.insert(25);
	T.insert(15);
	T.insert(10);
	T.insert(5);
	T.insert(35);
	T.remove(35);
	return 0;
}