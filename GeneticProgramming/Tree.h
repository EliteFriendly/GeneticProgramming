#pragma once
#include <functional>
#include <vector>
#include <iostream>

using namespace std;

class Tree
{
private:
	
	int numberFunc;//����� ������� ������� ������������ � ����
	int numVertices=0;//���������� ������
	int numNodes;//���������� ����� ����

	double coef;//����������� ����� x � ��������

	bool unarFuncUs;//������������ �� ������� ������� true/false
	bool lastVertice = false;
	Tree* left = nullptr;
	Tree* right = nullptr;


	vector<string> strUnarFunc = { "x","sin","cos","ln","exp" };//���������� ����� �������
	vector<string> strBinaryFunc = { "+","-","*","/" };//���������� ����� �������
	vector<function <double(double)>> unarFunc = {
		[](double x) {return x; },
		[](double x) {return sin(x); },
		[](double x) {return cos(x); },
		[](double x) {return log(x); },
		[](double x) {return exp(x); }

	};//������� �� ������� �������
	vector<function <double(double, double)>> binaryFunc = {
		[](double x,double y) {return x + y; },
		[](double x,double y) {return x - y; },
		[](double x,double y) {return x * y; },
		[](double x,double y) {return x / y; }
	};//������� �� �������� �������


	

public:
	Tree() {}
	Tree(const Tree &copy) :numberFunc(copy.numberFunc), lastVertice(copy.lastVertice),
		unarFuncUs(copy.unarFuncUs), coef(copy.coef),numVertices(copy.numVertices),numNodes(copy.numNodes) {
		//��������� ������ ����� �� ���� ���� ��������������� ���������
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
	
	void randFunc() {//������������ ��� ��������� �������
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

