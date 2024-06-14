#include <iostream>
#include <vector>
#include "MutationGP.h"
#include "Tree.h"
#include "CrossoverGP.h"

using namespace std;


/*
щрнр юкцнпхрл пеюкхгнбюм рнкэйн дкъ 1 бундю х 1 бшундю

*/


void main() {
	srand(6);
	//srand(time(0));



	vector <double> change = { 1.0, 2.0, 3.0 };
	MutationGP mut;
	Tree proba1(10);
	Tree proba2(10);
	CrossoverGP cross;

	Tree child = cross.getChild(proba1, proba2);

	proba1.out();
	cout << endl;
	proba2.out();
	cout << endl;
	child.out();
}