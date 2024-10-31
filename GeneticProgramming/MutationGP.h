#pragma once
#include <iostream>
#include <vector>
#include"Tree.h"
using namespace std;

class MutationGP
{
protected:
	int treeSize;

public:

	virtual void doMutChild(Tree&) = 0;

	//void getMutChild2(Tree& ind) {
	//	int r = ind.getNumNodes();
	//	int chosenNode;//“о что будет провер€ть мутируетс€ ли узел
	//	for (int i = 0; i < r; i++) {
	//		chosenNode = rand() % r + 1;
	//		if (chosenNode == 0) {
	//			//≈сли веро€тность прокнула, то идем о i-го узла
	//			Tree* node = &ind;
	//			bool t = false;
	//			while (t == false) {
	//				if (node->getNumNodes() == i) {
	//					t = true;
	//					break;
	//				}
	//				if (node->getLeft() != nullptr and i <= node->getLeft()->getNumNodes()) {
	//					node = node->getLeft();
	//					continue;
	//				}
	//				if (node->getRight() != nullptr and i <= node->getRight()->getNumNodes()) {
	//					node = node->getRight();
	//					continue;
	//				}

	//			}
	//			node->randFunc();
	//		}
	//	}

	//}

	//void getMutChild(Tree &ind) {
	//	int r = ind.getNumNodes();
	//	int chosenNode = rand() % r+1;
	//	Tree* node = &ind;
	//	bool t = false;
	//	while (t==false) {
	//		if (node->getNumNodes() == chosenNode) {
	//			t = true;
	//			break;
	//		}
	//		if (node->getLeft()!= nullptr and chosenNode <= node->getLeft()->getNumNodes()) {
	//			node = node->getLeft();
	//			continue;
	//		}
	//		if (node->getRight() != nullptr and chosenNode <= node->getRight()->getNumNodes()) {
	//			node = node->getRight();
	//			continue;
	//		}

	//	}


	//	node->randFunc();
	//}
};



class treeMutation : public MutationGP {

	void doMutChild(Tree& ind) {

		int r = ind.getNumNodes();
		int chosenNode = rand() % (r + 1);
		Tree* node = &ind;
		bool t = false;//ƒошли ли до нужного узла
		while (t == false) {
			/*
			ќтсчет узлов начинаетс€ слева, тем самым мы провер€ем если выбранный узел больше 
			первого узла слева, то значит выбранный узел точно правее и наоборот
			
			*/
			if (node->getNumNodes() == chosenNode) {
				t = true;
				break;
			}
			if (node->getLeft() != nullptr and chosenNode <= node->getLeft()->getNumNodes()) {
				node = node->getLeft();
				continue;
			}
			if (node->getRight() != nullptr and chosenNode <= node->getRight()->getNumNodes()) {
				node = node->getRight();
				continue;
			}

		}
		node->operator=(Tree(treeSize,ind.getAmmInputs()));
		int nodes = 0, lvl = 0;
		ind.recountLayers(lvl);
		ind.countNodes(nodes);
	}

};




class pointMutation : public MutationGP {

	void doMutChild(Tree& ind) {
		int r = ind.getNumNodes()+1;
		int chosenNode;//“о что будет провер€ть мутируетс€ ли узел
		for (int i = 0; i < r; i++) {

			//ѕровер€ем каждый узел на шанс мутации
			//ћутаци€ только средн€€

			chosenNode = rand() % (r + 1);
			if (chosenNode == 0) {
				//≈сли веро€тность прокнула, то идем о i-го узла
				Tree* node = &ind;
				bool t = false;
				while (t == false) {
					/*
						ќтсчет узлов начинаетс€ слева, тем самым мы провер€ем если выбранный узел больше
					первого узла слева, то значит выбранный узел точно правее и наоборот

					*/
					if (node->getNumNodes() == i) {
						t = true;
						break;
					}
					if (node->getLeft() != nullptr and i <= node->getLeft()->getNumNodes()) {
						node = node->getLeft();
						continue;
					}
					if (node->getRight() != nullptr and i <= node->getRight()->getNumNodes()) {
						node = node->getRight();
						continue;
					}

				}
				node->randFunc();
			}
		}

	}

};