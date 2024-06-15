#pragma once
#include <iostream>
#include<vector>
#include<functional>
#include "MutationGP.h"
#include"CrossoverGP.h"
#include"Tree.h"

class SelectionGP
{
	int tournamentSize=3;
public:
	SelectionGP() {}
	SelectionGP(const SelectionGP& copy) :tournamentSize(copy.tournamentSize) {}
	SelectionGP(int tournamentSize) :tournamentSize(tournamentSize) {}
	int getNumParents(vector<Tree>& arrIndividuals) {
		double fitness = -9999999;
		int number, numberBest;
		for (int i = 0; i < tournamentSize; i++) {

			number = rand() % arrIndividuals.size();
			if (arrIndividuals[number].getFitness() > fitness) {
				fitness = arrIndividuals[number].getFitness();
				numberBest = number;
			}
		}


		return numberBest;
	}
};

