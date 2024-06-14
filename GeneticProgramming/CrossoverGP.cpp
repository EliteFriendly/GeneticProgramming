#include "CrossoverGP.h"

Tree CrossoverGP::getChild(Tree &first, Tree &second)
{
	//¬ыбор рандомного узла первого родител€
	Tree child (first);
	int r = child.getNumNodes();
	int chosenNode = rand() % r + 1;

	//¬ыбор рандомного узла дл€ 2 родител€
	int r2 = second.getNumNodes();
	chosenNode = rand() % r2 + 1;
	Tree* nodeParent = &second;
	bool t = false;
	//Ќачало спуска до этого узла
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
	//«амена у ребенка выбраного узла у первого и второго родител€
	child.replaceNode(chosenNode, *nodeParent);
	//»спользуетс€ чтобы пронумеровать все узлы
	int z = 0;
	child.countNodes(z);
	return child;
}
