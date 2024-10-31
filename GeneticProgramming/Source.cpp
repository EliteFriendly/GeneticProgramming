#include <iostream>
#include <vector>
#include "MutationGP.h"
#include "Tree.h"
#include "CrossoverGP.h"
#include <fstream>
#include "GeneticProgramming.h"
#include "GeneratePoints.h"
using namespace std;

double func0(double x) {
	return x;
}
double func1(double x) {
	return 3*sin(x) + 5*cos(x);
}


double func2(double x) {
	return pow(10*x,0.5);
}
double func3(double x) {
	return pow(x, 1.5) + 10 * sin(x);
}

/*
* ЗАПОМНИТЬ 
* random_device rd;

		mt19937_64 gen(rd());
		ГЕНЕРАТОР БЕЗ ОГРАНИЧЕНИЙ

ЭТОТ АЛГОРИТМ РЕАЛИЗОВАН ТОЛЬКО ДЛЯ 1 ВЫХОДА

Из за чего алгоритм может перестать работать:
Исправил ChosenNode с rand()%r+1 на то что стоит(?)




Что нужно изменить:




Оптимизация момент:



*/

void yi(int* in) {
	in[0];
}


void main() {
	setlocale(0, "");
	//srand(10);
	srand(71);
	//Формирование выборки для обучения
	int ammount = 100;
	double left = 0.2;
	double right = 10;
	double h = (right - left) / ammount;
	double** x = new double*[ammount];
	double* y = new double[ammount];


	for (int i = 0; i < ammount; i++) {
		x[i] = new double[1];
		x[i][0] = left + h * i;
		y[i] = func3(x[i][0]);
	}

	GeneticProgramming proba(1.2, 3, 3);
	proba.startTrain(x,1, y,ammount, 50, 50);
	
	cout << proba.getBest().getFunc();

}