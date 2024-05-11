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
		[](double x) {return sin(x); },
		[](double x) {return cos(x); },
		[](double x) {return log(x); },
		[](double x) {return exp(x); },
		[](double x) {return x; }

	};//������� �� ������� �������
	vector<function <double(double,double)>> binarFunc = {
		[](double x,double y) {return x+y; },
		[](double x,double y) {return x-y; },
		[](double x,double y) {return x*y; },
		[](double x,double y) {return x/y; }
	};//������� �� �������� �������

	int numberFunc;//����� ������� ������� ������������ � ����
	int numVertices=0;//���������� ������

	double coef;//����������� ����� x � ��������

	bool unarFuncUs;//������������ �� ������� ������� true/false
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

