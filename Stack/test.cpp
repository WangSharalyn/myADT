// #include "Stack_vector.h"
#include "application.h"
#include <iostream>
#include <string.h>

using std::cout;
using std::endl;

int main() {
	/*Stack<int> s1;
	s1.push(1);
	s1.push(2);
	s1.push(3);
	cout << s1.top() << endl;
	s1.pop();
	cout << s1.top() << endl;
	cout << s1.size() << endl;*/

	// conversion(5, 2);
	// int a[5] = { 1, 2, 3, 4, 5 };
	// int b[5] = { 1, 5, 2, 3, 4 };
	
	// cout << stackPermutation(a, 5, b) << endl;
	/*char a[] = "(( 3+5)*8]";
	cout << paren(a, 0, strlen(a)) << endl;
	char b[] = "({1+2}*(4+5))";
	cout << paren(b, 0, strlen(b)) << endl;*/

	char a[] = "9+(3-1)*3+10/2";
	cout << evaluate(a) << endl;

	return 0;
}