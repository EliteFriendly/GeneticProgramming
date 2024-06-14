#include "Tree.h"

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
		}
		cout << strUnarFunc[numberFunc];
		if (lastVertice==false) {
			cout << '(';
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

void Tree::changeCoef(vector<double>& in,int &z)
{
	//Заполнение будет происходить слева направо
	if (left != nullptr) {//Идем сначала по левой стороне до конца
		left->changeCoef(in, z);
	}
	if (right != nullptr) {//Если нет ничего слева
		right->changeCoef(in, z);
	}
	if (lastVertice) {
		if (z >= in.size()) {//Слуай если выйдет за границы массива
			coef = 0;
		}
		else {

			coef = in[z];//Замена коэффициентов в слечае если все ок
		}
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
	if (right != nullptr) {//Если справа что то есть то это точно унарная функци
		return unarFunc[numberFunc](right->getValue(x));
		
	}
	if (lastVertice) {//Если дошли до вершины
		return coef * unarFunc[numberFunc](x);
	}
	else {//Если попались в унарную функцию
		return binaryFunc[numberFunc](left->getValue(x),right->getValue(x));
	}
	
}
