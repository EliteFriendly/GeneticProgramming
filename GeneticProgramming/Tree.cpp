#include "Tree.h"

Tree::Tree(int d)
{
	//Случай если дошли до самого конца
	if (d == 0) {
		unarFuncUs = true;
		numberFunc = 0;
		numVertices = 1;
		return;
	}
	
	int r = rand() % 2;
	
	
	if (r) {
		//В случае если унарная
		unarFuncUs = true;
		
		numberFunc = rand() % (unarFunc.size());
		//Tree a(d - 1);
		right = new Tree(d-1);
	}
	else {
		//В случае если бинарная
		unarFuncUs = false;
		numberFunc = rand() % (binarFunc.size());
		//Tree l(d - 1);
		//Tree r(d - 1);
		left = new Tree(d - 1);
		right = new Tree(d - 1);
	}

}

void Tree::out()
{

	if (left != nullptr) {
		cout << '(';
		left->out();
	}
	if (unarFuncUs) {
		if (numberFunc == 0) {
			cout << coef << '*';
		}
		cout<<strUnarFunc[numberFunc];
	}
	else {
		cout<< strBinaryFunc[numberFunc];
	}
	if (right != nullptr) {
		right->out();
		cout << ')';
	}
}

double Tree::getNumVertices()
{
	if (left == nullptr and right == nullptr) {
		return numVertices;
	}
	if (left != nullptr) {
		numVertices += left->getNumVertices();
	}
	if (right != nullptr) {
		numVertices += right->getNumVertices();
	}
	return numVertices;
}
