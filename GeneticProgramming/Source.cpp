#include <iostream>
#include <vector>
#include "MutationGP.h"
#include "Tree.h"
#include "CrossoverGP.h"
#include "GeneticProgramming.h"
using namespace std;


double func1(double x) {
	return sin(x) + cos(x);
}




/*
ЭТОТ АЛГОРИТМ РЕАЛИЗОВАН ТОЛЬКО ДЛЯ 1 ВХОДА И 1 ВЫХОДА

*/


void main() {
	setlocale(0, "");
	//srand(10);
	srand(time(0));
	//Формирование выборки для обучения
	int ammount = 100;//Количество точен
	int i1 = 0;//Счетчики
	int i2 = 0;
	double left = 0;
	double right = 10;
	double h = (right - left) / ammount;
	vector<double> xTrain(int(0.8 * ammount));
	vector<double> yTrain(int(0.8 * ammount));
	vector<double> xTest(int(0.2 * ammount));
	vector<double> yTest(int(0.2 * ammount));
	for (int i = 0; i < ammount; i++) {
		if (i % 5 != 0) {
			xTrain[i1] = left + (i-1) * h;
			yTrain[i1] = func1(xTrain[i1]);
			i1++;
		}
		else {
			xTest[i2] = left + (i-1) * h;
			yTest[i2] = func1(xTest[i2]);
			i2++;
		}
	}

	
	GeneticProgramming proba(1, 5, 5);
	proba.startTrain(xTrain, yTrain, 100, 100);

	proba.getBest().out();


	//for (int i = 0; i < 80; i++) {
	//	cout << proba.getBest().getValue(xTrain[i]) << " " ;
	//	cout << yTrain[i]<<endl;

	//}



}