#include "Tree.h"
#include <sstream>


void Tree::countNodes(int& ammount)
{
	
	if (left != nullptr) {
		left->countNodes(ammount);
	}
	if (right != nullptr) {
		right->countNodes(ammount);
	}
	numNodes = ammount;
	ammount++;
}

void Tree::recountLayers(int level)
{
	layerLevel = level;
	if (left != nullptr) {
		left->recountLayers(level+1);
	}
	if (right != nullptr) {
		right->recountLayers(level+1);
	}
}

void Tree::calcFitness(double** x, double* y, int size,double K1)
{
	double error = 0;
	for (int i = 0; i < size; i++) {
		error += pow(y[i] - getValue(x[i]), 2);
	}
	fitness = (1 / (1 + pow(error, 0.5))) * (20 - K1 * numNodes);
	if (fitness == NAN) {
		cout << 1;
	}
}

Tree::Tree(int d, int numInputs)
{
	ammInputs = numInputs;
	//������ ���� ����� �� ������ �����
	if (d == 0) {
		lastVertice = true;
		if (rand() % 2) {
			numInput = rand() % numInputs;
			numVertices = 0;
		}
		else {
			numVertices = 1;
			coef = 1;
		}
		return;
	}
	
	int r = rand() % 2;
	
	
	if (r) {
		//� ������ ���� �������
		unarFuncUs = true;
		
		numberFunc = rand() % (unarFunc.size());
		//Tree a(d - 1);
		right = new Tree(d-1,numInputs);
	}
	else {
		//� ������ ���� ��������
		unarFuncUs = false;
		numberFunc = rand() % (binaryFunc.size());
		//Tree l(d - 1);
		//Tree r(d - 1);
		left = new Tree(d - 1,numInputs);
		right = new Tree(d - 1,numInputs);
	}
}


string Tree::getFunc()
{
	stringstream ss;
	if (lastVertice) {
		if (numVertices == 1) {
			ss << coef;
		}
		else {
			ss <<'X' << numInput;
		}

	}
	if (left != nullptr) {
		ss << '(';
		ss<<left->getFunc();
	}

	if (unarFuncUs) {
		
		if (numberFunc == 0 and !lastVertice) {
			ss << '(';
		}
		else {
			ss << strUnarFunc[numberFunc];
			if (lastVertice == false) {
				ss << '(';
			}
		}

		


	}
	else {
		if (!lastVertice) {
			ss << strBinaryFunc[numberFunc];
		}

	}
	if (right != nullptr) {
		ss<<right->getFunc();
		ss << ')';
	}

	return ss.str();
}

void Tree::changeCoef(double *in,int &z)
{
	//���������� ����� ����������� ����� �������
	if (left != nullptr) {//���� ������� �� ����� ������� �� �����
		left->changeCoef(in, z);
	}
	if (right != nullptr) {//���� ��� ������ �����
		right->changeCoef(in, z);
	}
	if (lastVertice and numVertices == 1) {
		coef = in[z];//������ ������������� � ������ ���� ��� ��
		z++;//������ � �������!!!
	}
}

double Tree::getNumVertices()
{

	if (lastVertice) {
		return numVertices;
	}

	if (left != nullptr and right != nullptr) {
		numVertices = left->getNumVertices() + right->getNumVertices();
	}
	else {
		if (left != nullptr) {
			numVertices = left->getNumVertices();
		}
		if (right != nullptr) {
			numVertices = right->getNumVertices();
		}
	}

	return numVertices;
}

double Tree::getValue(double* x)
{
	//if (right != nullptr and left ==nullptr) {//���� ������ ��� �� ���� �� ��� ����� ������� ������

	//	return unarFunc[numberFunc](right->getValue(x));
	//	
	//}
	if (lastVertice) {//���� ����� �� �������
		if (numVertices==1) {
			return coef;
		}
		if (numVertices==0) {
			return x[numInput];
		}
		else {
			cout << "����������������";
			exit(0);
		}
	}

	if (unarFuncUs) {
		return unarFunc[numberFunc](right->getValue(x));
	}
	else {//���� �������� � �������� �������
		return binaryFunc[numberFunc](left->getValue(x),right->getValue(x));
	}
	
}

void Tree::replaceNode(int search, Tree& newNode)//������ ���������� ����
{
	if (numNodes == search) {//���� �� ����� �� ���� ��� ����� �� �������
		*this = newNode;
		return;
	}
	//����� �� ������ ����� ���� �� ����� ����������� ������
	if (left != nullptr and search <= left->getNumNodes()) {
		left->replaceNode(search, newNode);
	}
	if (right != nullptr and search <= right->getNumNodes()) {
		right->replaceNode(search, newNode);
	}
}

void Tree::trainWithDE(double** x, double* y, int size, double K1)
{
	int numVertices = getNumVertices();
	if (numVertices == 0) {
		calcFitness(x, y, size, K1);
		return;
	}
	function <double(double*)> func = [&](double* input) {
		int i = 0;
		changeCoef(input, i);
		calcFitness(x, y, size, K1);
		return fitness;
		};

	double* limits = new double[numVertices * 2];

	for (int i = 0; i < numVertices * 2; i++) {
		if (i % 2) {
			limits[i] = 10;
		}
		else {
			limits[i] = -10;
		}
	}


	DiffEvolution DE(func, limits, numVertices, "targetToBest1", "max");
	DE.startSearch(0.01, 0.5, 0.5, 50, 50);
	int i = 0;
	double* coef = DE.getBestCoordinates();
	changeCoef(coef, i);
	calcFitness(x, y, size, K1);

}
