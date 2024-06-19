#include <iostream>
#include <vector>
#include "MutationGP.h"
#include "Tree.h"
#include "CrossoverGP.h"
#include "GeneticProgramming.h"
using namespace std;


double func1(double x) {
	return pow(x,0.5);
}




/*
���� �������� ���������� ������ ��� 1 ����� � 1 ������

*/


void main() {
	setlocale(0, "");
	//srand(10);
	srand(time(0));
	//������������ ������� ��� ��������
	int ammount = 100;//���������� �����
	int i1 = 0;//��������
	int i2 = 0;
	double left = 1;
	double right = 10;
	double h = (right - left) / ammount;
	vector<double> xTrain(ammount);
	vector<double> yTrain(ammount);
	for (int i = 0; i < ammount; i++) {
		
		xTrain[i] = left + (i-1) * h;
		yTrain[i] = func1(xTrain[i]);

		
		
	}

	
	GeneticProgramming proba(1, 4, 3);
	proba.startTrain(xTrain, yTrain, 50, 50);

	proba.getBest().out();


	//for (int i = 0; i < 80; i++) {
	//	cout << proba.getBest().getValue(xTrain[i]) << " " ;
	//	cout << yTrain[i]<<endl;

	//}



}