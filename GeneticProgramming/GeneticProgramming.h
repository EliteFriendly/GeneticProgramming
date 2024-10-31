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
	Tree* arrayIndividuals;
	Tree* arrayChildren;
	int ammInputs;

	SelectionGP* selection;
	CrossoverGP* crossover;
	MutationGP* mutation;
	FormingGP forming;

	void findBest();
public:
	GeneticProgramming(double K1, int treeDepth,int tournamentSize) :K1(K1), treeDepth(treeDepth), tournamentSize(tournamentSize){
		
	}
	void startTrain(double** x, int ammInputs, double* y, int size, int numIndividuals, int numGeneration);
	Tree getBest() {
		return bestIndividual;
	}
	double getError(double** x, double *y, int size) {
		double sum = 0;//Среднеквадратичная ошибка
		for (int i = 0; i < size; i++) {
			sum += pow(bestIndividual.getValue(x[i]) - y[i], 2);
		}
		sum = pow(sum / size, 0.5);
		return sum;




	}
};

