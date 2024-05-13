#include <iostream>
#include <vector>
#include "Tree.h"

using namespace std;

void main() {
	srand(3);
	int z = 0;
	vector <double> change = { 1.0, 2.0, 3.0 };

	int x = 4;
	int& y = x;
	int q = 5;
	int* w = &q;
	y = *w;
	cout << x;

	Tree proba(6);
	proba.changeCoef(change, z);
	proba.out();
	cout << endl;
	cout << proba.getValue(1);
}