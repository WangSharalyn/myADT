#include <iostream>
#include "Vector.h"
using std::cout;
using std::endl;

int main() {
	// ≤‚ ‘ππ‘Ï∫Ø ˝
	/*Vector<int> vec;
	Vector<char> vec2{ 3, 'a'};*/

	int a[4] = { 1, -1, 0 ,5};
	Vector<int> vec3(a, 0, 4);
	vec3.printV();
	vec3.insert(0, 0);

	//Vector<int> vec4{ vec3 };
	//Vector<int> vec5{ vec3, 0, 1 };

	/*cout << "vec.size:"<< vec.size() << endl;
	cout << "vec2.size:" << vec2.size() << endl;
	cout << "vec3.size:" << vec3.size() << endl;
	cout << "vec4.size:" << vec4.size() << endl;
	cout << "vec5.size:" << vec5.size() << endl;
	cout << "vec.empty:" << vec.empty() << endl;*/
	//cout << "vec3.find(2):" << vec3.find(2) << endl;
	//cout << "vec3.search(1):" << vec3.search(4) << endl;
	//cout << "vec3[2]:" << vec3[2] << endl;
	//cout << "vec3.insert(0, 0):" << vec3[0] << endl;
	vec3.printV();
	cout << "-------------------------" << endl;
	vec3.sort();
	cout << "-------------------------" << endl;
	vec3.printV();

	return 0;
}