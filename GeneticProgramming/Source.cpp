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


!!!Не знаю что делать если функциональное множества меняется на термальное

*Из за чего алгоритм может перестать работать:

Исправил ChosenNode с rand()%r+1 на то что стоит(?)

Перетащил findReach в родителя


*Что нужно изменить:
Добавить деструкторов во все щели, чтобы не было переполнения памяти	



*Оптимизация момент:



*/

void yi(int* in) {
	in[0];
}


void main() {
	setlocale(0, "");
	//srand(10);
	srand(72);
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
	for (int i = 0; i < 1000; i++) {
		srand(i);
		cout << "Номер рандомайзера = " << i<<endl;
		GeneticProgramming proba(1.2, 3, 3);
		proba.startTrain(x, 1, y, ammount, 20, 100);
	}

	
	//cout << proba.getBest().getFunc();

}