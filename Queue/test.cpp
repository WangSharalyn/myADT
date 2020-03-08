#include <ostream>
#include "Queue_list.h"

int main() {
	Queue<int> q;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	std::cout << q.dequeue() << std::endl;
	q.printL();
	return 0;
}