#pragma once
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

class Tree
{
private:
	vector<string> strUnarFunc = { "x","sin(","cos(","ln(","exp^("};//Символьный вывод функции
	vector<string> strBinaryFunc = { "+","-","*","/" };//Символьный вывод функции
	vector<function <double(double)>> unarFunc = {
		[](double x) {return sin(x); },
		[](double x) {return cos(x); },
		[](double x) {return log(x); },
		[](double x) {return exp(x); },
		[](double x) {return x; }

	};//Выборка из унарных функций
	vector<function <double(double,double)>> binarFunc = {
		[](double x,double y) {return x+y; },
		[](double x,double y) {return x-y; },
		[](double x,double y) {return x*y; },
		[](double x,double y) {return x/y; }
	};//Выборка из бинарных функций

	int numberFunc;//Номер функции который используется в узле
	int numVertices=0;//Количество вершин

	double coef;//Коэффициент перед x в вершинах

	bool unarFuncUs;//Используется ли унарная функция true/false
	Tree* left = nullptr;
	Tree* right = nullptr;

public:
	Tree(int d);
	void out();
	double getNumVertices();
	~Tree() {
		if (left != nullptr) {
			left->~Tree();
		}
		if (right != nullptr) {
			right->~Tree();
		}
	}
};

