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

	double coef;//Коэффициент перед x в вершинах

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
		[](double x) {return log(x); },
		[](double x) {return exp(x); }

	};//Выборка из унарных функций
	vector<function <double(double, double)>> binaryFunc = {
		[](double x,double y) {return x + y; },
		[](double x,double y) {return x - y; },
		[](double x,double y) {return x * y; },
		[](double x,double y) {return x / y; }
	};//Выборка из бинарных функций


	

public:
	Tree() {}
	Tree(const Tree &copy) :numberFunc(copy.numberFunc), lastVertice(copy.lastVertice),
		unarFuncUs(copy.unarFuncUs), coef(copy.coef),numVertices(copy.numVertices),numNodes(copy.numNodes) {
		//Выделение памяти чтобы не было кучи взаимосвязанных индивидлв
		if (copy.left != nullptr) {
			left = new Tree(*copy.left);
		}
		if (copy.right != nullptr) {
			right = new Tree(*copy.right);
		}
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
	~Tree() {
		if (left != nullptr) {
			left->~Tree();
		}
		if (right != nullptr) {
			right->~Tree();
		}
	}
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

