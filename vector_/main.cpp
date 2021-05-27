#include <iostream>
#include "vector_.h"
using namespace std;






void main() {
	vector_ t(5,7);
	vector_ t2(3,2);
	vector_ t3;
	t.operator=(t2);
	t = t2;
	cout << t;
	//t.resize(88);

	t3 = t2 = t;
	t3.operator=(t2.operator=(t));

	t = t;
	t.operator=(t);
	system("pause");
}