#pragma once
#include <iostream>
#include<vector>
#include<functional>
#include "MutationGP.h"
#include"CrossoverGP.h"
#include"Tree.h"
#include <random>

class SelectionGP
{
protected:
	int tournamentSize=3;
	double* arrayFitness = nullptr;
	int sizeArray;


	int velocityChoice(double* velocityArr) {
		//random_device rd;

		mt19937 gen(rand());

		double sum = velocityArr[0];
		int number = 0;
		double probability = gen() % 1000000 / 1000000.0;
		while (probability > sum) {
			number++;
			if (number == sizeArray) {
				return number - 1;
			}
			sum += velocityArr[number];
		}
		return number;

	}


public:

	void setTournamentSize(int ts) {
		tournamentSize = ts;
	}


	virtual void setFitnessArray(double* inputArray, int size) {
		arrayFitness = inputArray;//��� �� ����� �������� ������, ������ ��� �� �� ����� ��� ��������
		sizeArray = size;
	}


	void setArrIndividuals(Tree*& arrIndividuals, int size) {

		sizeArray = size;

		
		// ����� �������������� � ���� ���������� ���������
		int listLength = size;

		while (listLength--)
		{
			bool swapped = false;

			for (int i = 0; i < listLength; i++)
			{
				if (arrIndividuals[i].getFitness() > arrIndividuals[i+1].getFitness())
				{
					Tree tmp (arrIndividuals[i]);
					arrIndividuals[i] = arrIndividuals[i + 1];
					arrIndividuals[i + 1] = tmp;
					swapped = true;
				}
			}

			if (swapped == false)
				break;
		}

		if (arrayFitness != nullptr) {
			delete[] arrayFitness;
		}

		arrayFitness = new double[size];

		for (int i = 0; i < size; i++) {
			arrayFitness[i] = arrIndividuals[i].getFitness();
		}
		
		setFitnessArray(arrayFitness, sizeArray);

	}//����� ���� ��� ��������������� ������

	virtual int getNumParents() = 0;

	SelectionGP() {}
};




class RankedSelection :public SelectionGP {

protected:
	double* rankArray = nullptr;


	void ranked() {
		rankArray = new double[sizeArray];
		int rank = 1;
		int wh = 0;
		for (int i = 0; i < sizeArray - 1; i++) {
			if (arrayFitness[i] == arrayFitness[i + 1]) {
				//���� ����������� ���������� ����������� ���������� ��� ����������
				while (arrayFitness[i + wh] == arrayFitness[i + wh + 1]) {
					wh++;
					if ((i + wh + 1) >= sizeArray) {
						break;
					}
				}
				//������ ����� ��� ��������� �����������, ��� ����, ����� ������������ �����������
				for (int j = 0; j <= wh; j++) {
					rankArray[i + j] = double(rank) / (wh + 1);
				}
				i += wh;
				wh = 0;

			}
			else {
				rankArray[i] = rank;
			}
			rank++;
		}
		rankArray[sizeArray - 1] = rank;

		double sum = 0;

		for (int i = 0; i < sizeArray; i++) {
			sum += rankArray[i];
		}
		for (int i = 0; i < sizeArray; i++) {
			rankArray[i] /= sum;
		}
		
	}

public:

	void setFitnessArray(double* inputArray, int size) {
		SelectionGP::setFitnessArray(inputArray, size);
		ranked();

	}
	int getNumParents() {
		return (velocityChoice(rankArray));
	}
};



class ProportionalSelection :public SelectionGP {
protected:
	double* normalArray = nullptr;

	void normalisation() {
		normalArray = new double[sizeArray];
		double min = 0;
		//������������ �� ������������� ��������
		for (int i = 0; i < sizeArray; i++) {
			normalArray[i] = arrayFitness[i];
			if (min > normalArray[i]) {
				min = normalArray[i];
			}
		}
		if (min < 0) {
			for (int i = 0; i < sizeArray; i++) {
				normalArray[i] += min;
			}
		}

		double sum = 0;
		//������������
		for (int i = 0; i < sizeArray; i++) {
			sum += normalArray[i];
		}
		for (int i = 0; i < sizeArray; i++) {
			normalArray[i] /= sum;
		}
	}

public:

	void setFitnessArray(double* inputArray, int size) {
		SelectionGP::setFitnessArray(inputArray, size);
		normalisation();

	}

	int getNumParents() {
		return (velocityChoice(normalArray));
	}
};




class TournamentSelection :public SelectionGP {


	int getNumParents() {
		double fitness = -9999999;
		int number, numberBest;
		for (int i = 0; i < tournamentSize; i++) {
			number = rand() % sizeArray;
			if (arrayFitness[number] > fitness) {
				fitness = arrayFitness[number];
				numberBest = number;
			}
		}

		return numberBest;
	}






};