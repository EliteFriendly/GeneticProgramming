#include <iostream>
#include <vector>
#include "MutationGP.h"
#include "Tree.h"

using namespace std;

void main() {
	srand(2);
	//srand(time(0));
	int z = 0;


	vector <double> change = { 1.0, 2.0, 3.0 };
	MutationGP mut;
	Tree proba(5);
	proba.changeCoef(change, z);
	proba.out();

	mut.getMutChild(proba);
	cout << endl;
	proba.out();
	mut.getMutChild(proba);
	cout << endl;
	proba.out();
	cout << endl;
	cout << proba.getNumNodes()<<endl;
	//cout << proba.getValue(1);
}