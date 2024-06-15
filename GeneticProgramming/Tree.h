#pragma once
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

class Tree
{
private:
	
	int numberFunc;//Номер функции который используется в узле
	int numVertices=0;//Количество вершин
	int numNodes;//Количество узлов ниже

	double coef = 1;//Коэффициент перед x в вершинах
	double fitness=-9999999;//Ну тут понятно

	bool unarFuncUs;//Используется ли унарная функция true/false
	bool lastVertice = false;
	Tree* left = nullptr;
	Tree* right = nullptr;


	vector<string> strUnarFunc = { "x","sin","cos","ln","exp" };//Символьный вывод функции
	vector<string> strBinaryFunc = { "+","-","*","/" };//Символьный вывод функции
	vector<function <double(double)>> unarFunc = {
		[](double x) {return x; },
		[](double x) {return sin(x); },
		[](double x) {return cos(x); },
		[](double x) {if (x == 0) return 0.0; return log(abs(x)); },
		[](double x) {if (x > 10) return exp(10); return exp(x); }

	};//Выборка из унарных функций
	vector<function <double(double, double)>> binaryFunc = {
		[](double x,double y) {return x + y; },
		[](double x,double y) {return x - y; },
		[](double x,double y) {return x * y; },
		[](double x,double y) {if (y == 0) return 0.0; return x / y; }
	};//Выборка из бинарных функций


	

public:
	Tree() {}
	Tree(const Tree &copy) :numberFunc(copy.numberFunc), lastVertice(copy.lastVertice),
		unarFuncUs(copy.unarFuncUs), coef(copy.coef),numVertices(copy.numVertices),numNodes(copy.numNodes),fitness(copy.fitness),
		unarFunc(copy.unarFunc)
	{
		//Выделение памяти чтобы не было кучи взаимосвязанных индивидлв
		if (copy.left != nullptr) {
			//left = new Tree;
			left = new Tree(*(copy.left));
		}
		if (copy.right != nullptr) {
			//right = new Tree;
			right = new Tree(*(copy.right));
		}
	}

	void calcFitness(vector<double> x, vector<double> y,double K1);
	double getFitness() {
		return fitness;
	}
	Tree(int d);
	void out();
	void countNodes(int&);
	void changeCoef(vector<double>&,int&);
	double getNumVertices();
	double getValue(double x);
	int getNumNodes() {
		
		return numNodes;//numNodes;
	}
	//~Tree() {
	//	if (left != nullptr) {
	//		delete left;
	//	}
	//	if (right != nullptr) {
	//		delete right;
	//	}
	//}
	void replaceNode(int, Tree&);
	
	void randFunc() {//Используется для оператора мутации
		if (unarFuncUs) {
			numberFunc = rand() % unarFunc.size();
		}
		else {
			numberFunc = rand() % binaryFunc.size();
		}
	}

	Tree* getLeft() {
		if (left == nullptr) {
			return nullptr;
		}
		return left;
	}
	Tree* getRight() {
		if (right == nullptr) {
			return nullptr;
		}
		return right;
	}
};

