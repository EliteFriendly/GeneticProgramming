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
	double K1;//����������� ������������ ��� �������� �����������, ��� ���� ��� ������ ����� �������
	int treeDepth;
	Tree bestIndividual;
	int numIndividuals;
	int numGeneration;
	int tournamentSize;
	Tree* arrayIndividuals;
	Tree* arrayChildren;
	int ammInputs;

	SelectionGP selection;
	CrossoverGP crossover;
	MutationGP mutation;
	FormingGP forming;

	void findBest();
public:
	GeneticProgramming(double K1, int treeDepth,int tournamentSize) :K1(K1), treeDepth(treeDepth), tournamentSize(tournamentSize){
		selection = SelectionGP(tournamentSize);
	}
	void startTrain(double* x, double* y,int size,int numIndividuals,int numGeneration);
	Tree getBest() {
		return bestIndividual;
	}
	double getError(vector<double> x, vector<double>y) {
		double sum = 0;//������������������ ������
		for (int i = 0; i < x.size(); i++) {
			sum += pow(bestIndividual.getValue(x[i]) - y[i], 2);
		}
		sum = pow(sum / y.size(), 0.5);
		return sum;




	}
};

