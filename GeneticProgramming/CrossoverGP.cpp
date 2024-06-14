#include "CrossoverGP.h"

Tree CrossoverGP::getChilde(Tree &first, Tree &second)
{
	 //Поиск узла первого родителя
	Tree child (first);
	int r = child.getNumNodes();
	int chosenNode = rand() % r + 1;
	//Поиск узла для 2 родителя
	int r2 = second.getNumNodes();
	chosenNode = rand() % r2 + 1;
	Tree* nodeParent = &second;
	bool t = false;
	while (t == false) {
		if (nodeParent->getNumNodes() == chosenNode) {
			t = true;
			break;
		}
		if (nodeParent->getLeft() != nullptr and chosenNode <= nodeParent->getLeft()->getNumNodes()) {
			nodeParent = nodeParent->getLeft();
			continue;
		}
		if (nodeParent->getRight() != nullptr and chosenNode <= nodeParent->getRight()->getNumNodes()) {
			nodeParent = nodeParent->getRight();
			continue;
		}


	}

	child.replaceNode(chosenNode, *nodeParent);

	int z = 0;
	child.countNodes(z);
	return child;
}
