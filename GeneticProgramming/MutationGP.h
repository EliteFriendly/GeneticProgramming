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
	//	int chosenNode;//�� ��� ����� ��������� ���������� �� ����
	//	for (int i = 0; i < r; i++) {
	//		chosenNode = rand() % r + 1;
	//		if (chosenNode == 0) {
	//			//���� ����������� ��������, �� ���� � i-�� ����
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
		bool t = false;//����� �� �� ������� ����
		while (t == false) {
			/*
			������ ����� ���������� �����, ��� ����� �� ��������� ���� ��������� ���� ������ 
			������� ���� �����, �� ������ ��������� ���� ����� ������ � ��������
			
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
		int chosenNode;//�� ��� ����� ��������� ���������� �� ����
		for (int i = 0; i < r; i++) {

			//��������� ������ ���� �� ���� �������
			//������� ������ �������

			chosenNode = rand() % (r + 1);
			if (chosenNode == 0) {
				//���� ����������� ��������, �� ���� � i-�� ����
				Tree* node = &ind;
				bool t = false;
				while (t == false) {
					/*
						������ ����� ���������� �����, ��� ����� �� ��������� ���� ��������� ���� ������
					������� ���� �����, �� ������ ��������� ���� ����� ������ � ��������

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