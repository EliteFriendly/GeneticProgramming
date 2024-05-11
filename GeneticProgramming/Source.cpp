#include <iostream>
#include <vector>
#include "Tree.h"

using namespace std;

void main() {
	srand(3);
	Tree proba(3);
	proba.out();
	cout << endl;
	cout << proba.getNumVertices();
}