#include <iostream>
#include <vector>
#include "MutationGP.h"
#include "Tree.h"
#include "CrossoverGP.h"

using namespace std;


/*
яйнпее бяецн оняке йнохпнбюмхъ хмдхбхдю х опелемъъ й мелс лсрюжхч, лнфер онлемърэяъ х нпхцхмюк опнбепэ!!!!

*/


void main() {
	srand(3);
	//srand(time(0));

	int z = 0;
	int* x = &z;
	int* y =x;
	y = *(*y + 1);

	vector <double> change = { 1.0, 2.0, 3.0 };
	MutationGP mut;
	Tree proba1(2);
	proba1.out();
	cout << endl;
	Tree proba2(2);
	CrossoverGP cross;

	Tree child = cross.getChilde(proba1, proba2);

	proba1.out();
	cout << endl;
	proba2.out();
	cout << endl;
	child.out();
}