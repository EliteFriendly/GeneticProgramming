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


//void automat(int number) {
//
//
//	double left = 0.2;
//	double right = 10;
//	int ammount = 100;
//
//	GeneratePoints point(func0, left, right);
//	point.readFromFile("Input_" + to_string(number));
//
//	vector<double> x = point.getVectorX();
//	vector<double> y = point.getVectorY();
//
//	int i1 = 0, i2 = 0;
//	
//	vector<double> xTrain(ammount * 0.8);
//	vector<double> yTrain(ammount * 0.8);
//
//	vector<double> xTest(ammount * 0.2);
//	vector<double> yTest(ammount * 0.2);
//
//	for (int i = 0; i < ammount; i++) {
//		if (!(i % 5)) {
//			xTest[i2] = x[i];
//			yTest[i2] = y[i];
//			i2++;
//		}
//		else {
//			xTrain[i1] = x[i]; 
//			yTrain[i1] = y[i];
//			i1++;
//		}
//	}
//
//
//
//	GeneticProgramming proba(1.5, 2, 3);
//	proba.startTrain(x, y, 50, 50);
//
//	ofstream error("Results/Error_" + to_string(number) + ".txt");
//	error << proba.getError(xTest, yTest);
//	error.close();
//	
//	ofstream f("Results/Function_" + to_string(number) + ".txt");
//	f << proba.getBest().getFunc();
//	f.close();
//
//	proba.getBest().out();
//
//	ammount = 10000;
//	ofstream file("Results/Out_"+to_string(number)+".txt");
//	
//	double h = (right - left) / ammount;
//	for (int i = 0; i < ammount; i++) {
//		file << left + (i - 1) * h << '\t';
//		file << proba.getBest().getValue(left + i * h) << endl;
//	}
//	file.close();
//}


/*
ÝÒÎÒ ÀËÃÎÐÈÒÌ ÐÅÀËÈÇÎÂÀÍ ÒÎËÜÊÎ ÄËß 1 ÂÕÎÄÀ È 1 ÂÛÕÎÄÀ

*/

void yi(int* in) {
	in[0];
}


void main() {
	setlocale(0, "");
	//srand(10);
	srand(4);
	//Ôîðìèðîâàíèå âûáîðêè äëÿ îáó÷åíèÿ
	int ammount = 100;
	double left = 0.2;
	double right = 10;
	double h = (right - left) / ammount;
	double* x = new double[ammount];
	double* y = new double[ammount];

	for (int i = 0; i < ammount; i++) {
		x[i] = left + h * i;
		y[i] = func1(x[i]);
	}

	GeneticProgramming proba(1.5, 2, 3);
	proba.startTrain(x, y,ammount, 50, 50);
	
	cout << proba.getBest().getFunc();

	/*cout << "First func" << endl;
	automat(1);*/
	/*cout << "Second func" << endl;
	automat(2);*/
	/*cout << "Third func" << endl;
	automat(3);*/





}