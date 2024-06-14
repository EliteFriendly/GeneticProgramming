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
	//������ ���� ����� �� ������ �����
	if (d == 0) {
		unarFuncUs = true;
		lastVertice = true;
		numberFunc = 0;
		numVertices = 1;
		return;
	}
	
	int r = rand() % 2;
	
	
	if (r) {
		//� ������ ���� �������
		unarFuncUs = true;
		
		numberFunc = rand() % (unarFunc.size());
		//Tree a(d - 1);
		right = new Tree(d-1);
	}
	else {
		//� ������ ���� ��������
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
		if (lastVertice) {//� ��������� ������� ������ ���� ����� �� �����������
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
	//���������� ����� ����������� ����� �������
	if (left != nullptr) {//���� ������� �� ����� ������� �� �����
		left->changeCoef(in, z);
	}
	if (right != nullptr) {//���� ��� ������ �����
		right->changeCoef(in, z);
	}
	if (lastVertice) {
		if (z >= in.size()) {//������ ���� ������ �� ������� �������
			coef = 0;
		}
		else {

			coef = in[z];//������ ������������� � ������ ���� ��� ��
		}
		z++;//������ � �������!!!
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
	if (right != nullptr) {//���� ������ ��� �� ���� �� ��� ����� ������� ������
		return unarFunc[numberFunc](right->getValue(x));
		
	}
	if (lastVertice) {//���� ����� �� �������
		return coef * unarFunc[numberFunc](x);
	}
	else {//���� �������� � ������� �������
		return binaryFunc[numberFunc](left->getValue(x),right->getValue(x));
	}
	
}

void Tree::replaceNode(int search, Tree& newNode)//������ ���������� ����
{
	if (numNodes == search) {//���� �� ����� �� ���� ��� ����� �� �������
		unarFuncUs = newNode.unarFuncUs;
		if (unarFuncUs and left != nullptr) {//���� ������������� ������� �������
			left = nullptr;
		}
		lastVertice = newNode.lastVertice;
		if (newNode.left != nullptr) {//��������� ������
			left = new Tree(*newNode.left);
		}
		if (newNode.right != nullptr) {
			right = new Tree(*newNode.right);
		}
		numberFunc = newNode.numberFunc;//����� ������� ������� ������������ � ����
		numVertices = newNode.numVertices;//���������� ������

	}
	//����� �� ������ ����� ���� �� ����� ����������� ������
	if (left != nullptr and search <= left->getNumNodes()) {
		left->replaceNode(search, newNode);
	}
	if (right != nullptr and search <= right->getNumNodes()) {
		right->replaceNode(search, newNode);
	}
}
