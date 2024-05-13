#pragma once
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

class Tree
{
private:
	vector<string> strUnarFunc = { "x","sin(","cos(","ln(","exp^("};//���������� ����� �������
	vector<string> strBinaryFunc = { "+","-","*","/" };//���������� ����� �������
	vector<function <double(double)>> unarFunc = {
		[](double x) {return x; },
		[](double x) {return sin(x); },
		[](double x) {return cos(x); },
		[](double x) {return log(x); },
		[](double x) {return exp(x); }
		
	};//������� �� ������� �������
	vector<function <double(double,double)>> binaryFunc = {
		[](double x,double y) {return x+y; },
		[](double x,double y) {return x-y; },
		[](double x,double y) {return x*y; },
		[](double x,double y) {return x/y; }
	};//������� �� �������� �������

	int numberFunc;//����� ������� ������� ������������ � ����
	int numVertices=0;//���������� ������

	double coef;//����������� ����� x � ��������

	bool unarFuncUs;//������������ �� ������� ������� true/false
	bool lastVertice = false;
	Tree* left = nullptr;
	Tree* right = nullptr;

public:
	Tree(const Tree& copy) :numberFunc(copy.numberFunc), left(copy.left), right(copy.right), lastVertice(copy.lastVertice),
		unarFunc(copy.unarFunc), coef(copy.coef) {}
	Tree(int d);
	void out();
	void changeCoef(vector<double>&,int&);
	double getNumVertices();
	double getValue(double x);
	~Tree() {
		if (left != nullptr) {
			left->~Tree();
		}
		if (right != nullptr) {
			right->~Tree();
		}
	}
	Tree* getLeft() {
		if (left == nullptr) {
			return 0;
		}
		return left;
	}
	Tree* getRight() {
		if (right == nullptr) {
			return 0;
		}
		return right;
	}
};

