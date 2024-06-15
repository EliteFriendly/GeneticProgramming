#pragma once
#include <iostream>
#include<vector>
#include<functional>
#include "MutationGP.h"
#include"CrossoverGP.h"
#include"Tree.h"
#include "SelectionGP.h"
#include "FormingGP.h"
class GeneticProgramming
{
private:
	double K1;//Коэффициент используемый для подсчета пригодности, чем выше тем меньше будут деревья
	int treeDepth;
	Tree bestIndividual;
	int numIndividuals;
	int numGeneration;
	int tournamentSize;
	vector<Tree> arrayIndividuals;
	vector<Tree> arrayChildren;

	SelectionGP selection;
	CrossoverGP crossover;
	MutationGP mutation;
	FormingGP forming;

	void findBest();
public:
	GeneticProgramming(double K1, int treeDepth,int tournamentSize) :K1(K1), treeDepth(treeDepth), tournamentSize(tournamentSize){
		selection = SelectionGP(tournamentSize);
	}
	void startTrain(vector<double> x, vector<double>y,int numIndividuals,int numGeneration);
	Tree getBest() {
		return bestIndividual;
	}
};

