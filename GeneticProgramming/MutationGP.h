#pragma once
#include <iostream>
#include <vector>
#include"Tree.h"
using namespace std;

class MutationGP
{
private:


public:
	void getMutChild(Tree &ind) {
		int r = ind.getNumNodes();
		int chosenNode = rand() % r+1;
		Tree* node = &ind;
		bool t = false;
		while (t==false) {
			if (node->getNumNodes() == chosenNode) {
				t = true;
				break;
			}
			if (node->getLeft()!= nullptr and chosenNode <= node->getLeft()->getNumNodes()) {
				node = node->getLeft();
				continue;
			}
			if (node->getRight() != nullptr and chosenNode <= node->getRight()->getNumNodes()) {
				node = node->getRight();
				continue;
			}

		}


		node->randFunc();
	}
};

