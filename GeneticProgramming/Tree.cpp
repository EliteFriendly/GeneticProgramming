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
	if (lastVertice == false) {
		ammount++;
	}
	
	numNodes = ammount;
}

void Tree::calcFitness(double* x, double* y, int size,double K1)
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

Tree::Tree(int d)
{
	//Случай если дошли до самого конца
	if (d == 0) {
		unarFuncUs = true;
		lastVertice = true;
		numberFunc = 0;
		numVertices = 1;
		return;
	}
	
	int r = rand() % 2;
	
	
	if (r) {
		//В случае если унарная
		unarFuncUs = true;
		
		numberFunc = rand() % (unarFunc.size());
		//Tree a(d - 1);
		right = new Tree(d-1);
	}
	else {
		//В случае если бинарная
		unarFuncUs = false;
		numberFunc = rand() % (binaryFunc.size());
		//Tree l(d - 1);
		//Tree r(d - 1);
		left = new Tree(d - 1);
		right = new Tree(d - 1);
	}
	int i = 0;
	countNodes(i);
}

void Tree::out()
{

	if (left != nullptr) {
		cout << '(';
		left->out();
	}
	if (unarFuncUs) {
		if (lastVertice) {//У последней вершины обязан быть какой то коэффициент
			cout << coef << '*';
			cout << strUnarFunc[numberFunc];
			
		}
		
		else {
			if (numberFunc == 0 and !lastVertice) {
				cout << '(';
			}
			else {
				cout << strUnarFunc[numberFunc];
				if (lastVertice == false) {
					cout << '(';
				}
			}
			
		}
		
		
	}
	else {
		cout<< strBinaryFunc[numberFunc];
	}
	if (right != nullptr) {
		right->out();
		cout << ')';
	}
}

string Tree::getFunc()
{
	stringstream ss;
	if (left != nullptr) {
		ss << '(';
		ss<<left->getFunc();
	}
	if (unarFuncUs) {
		if (lastVertice) {//У последней вершины обязан быть какой то коэффициент
			ss << coef << '*';
			ss << strUnarFunc[numberFunc];

		}

		else {
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


	}
	else {
		ss << strBinaryFunc[numberFunc];
	}
	if (right != nullptr) {
		ss<<right->getFunc();
		ss << ')';
	}



	return ss.str();
}

void Tree::changeCoef(double *in,int &z)
{
	//Заполнение будет происходить слева направо
	if (left != nullptr) {//Идем сначала по левой стороне до конца
		left->changeCoef(in, z);
	}
	if (right != nullptr) {//Если нет ничего слева
		right->changeCoef(in, z);
	}
	if (lastVertice) {
		coef = in[z];//Замена коэффициентов в слечае если все ок
		z++;//Работа с памятью!!!
	}
}

double Tree::getNumVertices()
{

	if (lastVertice) {
		return numVertices;
	}
	if (left != nullptr) {
		numVertices += left->getNumVertices();
	}
	if (right != nullptr) {
		numVertices += right->getNumVertices();
	}
	return numVertices;
}

double Tree::getValue(double x)
{
	//if (right != nullptr and left ==nullptr) {//Если справа что то есть то это точно унарная функци

	//	return unarFunc[numberFunc](right->getValue(x));
	//	
	//}
	if (left == nullptr and right == nullptr) {//Если дошли до вершины
		double y = coef * unarFunc[numberFunc](x);
		return y;
	}
	if (unarFuncUs) {
		return unarFunc[numberFunc](right->getValue(x));
	}
	else {//Если попались в бинарную функцию
		return binaryFunc[numberFunc](left->getValue(x),right->getValue(x));
	}
	
}

void Tree::replaceNode(int search, Tree& newNode)//Замена выбранного узла
{
	if (numNodes == search) {//Если мы дошли до узла под каким то номером
		unarFuncUs = newNode.unarFuncUs;
		if (unarFuncUs and left != nullptr) {//Если наследовалась унарная функция
			left = nullptr;
		}
		lastVertice = newNode.lastVertice;
		if (newNode.left != nullptr) {//Выделение памяти
			left = new Tree(*(newNode.left));
		}
		if (newNode.right != nullptr) {
			right = new Tree(*(newNode.right));
		}
		numberFunc = newNode.numberFunc;//Номер функции который используется в узле
		numVertices = newNode.numVertices;//Количество вершин
		unarFunc = newNode.unarFunc;
		return;
	}
	//Поиск по другим узлам если не нашли подходящего номера
	if (left != nullptr and search <= left->getNumNodes()) {
		left->replaceNode(search, newNode);
	}
	if (right != nullptr and search <= right->getNumNodes()) {
		right->replaceNode(search, newNode);
	}
}

void Tree::trainWithDE(double* x, double* y, int size, double K1)
{
	int numVertices = getNumVertices();

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
