#include "GeneticProgramming.h"

void GeneticProgramming::findBest()
{
	for (int i = 0; i < numIndividuals; i++) {
		if (arrayIndividuals[i].getFitness() > bestIndividual.getFitness()) {
			bestIndividual = arrayIndividuals[i];
		}
	}
}

void GeneticProgramming::startTrain(double** x, int ammInputs, double* y, int size, int numIndividuals, int numGeneration)
{
	mutation = new pointMutation;

	GeneticProgramming::numIndividuals = numIndividuals;
	GeneticProgramming::numGeneration = numGeneration;
	arrayIndividuals = new Tree[numIndividuals];
	arrayChildren = new Tree[numIndividuals];
	//������ ������������ ���������
	for (int i = 0; i < numIndividuals; i++) {
		Tree t(treeDepth-1,ammInputs);
		int nodes = 0, lvl = 0;
		t.recountLayers(lvl);
		t.countNodes(nodes);
		arrayIndividuals[i] = t;
		arrayIndividuals[i].trainWithDE(x, y,size, K1);
	}

	findBest();//������ ����� ������� ��������
	//�������� ������ ���������
	int numParent1, numParent2;

	for (int i = 0; i < numGeneration; i++) {
		cout << "����� ��������� = " << i << endl;
		for (int j = 0; j < numIndividuals; j++) {

			numParent1 = selection.getNumParents(arrayIndividuals, numIndividuals);
			numParent2 = selection.getNumParents(arrayIndividuals, numIndividuals);
			while (numParent1 == numParent2) {
				numParent2 = selection.getNumParents(arrayIndividuals, numIndividuals);
			}
			
			arrayChildren[j] = crossover.getChild(arrayIndividuals[numParent1], arrayIndividuals[numParent2]);
			mutation->getMutChild(arrayChildren[j]);

			

			arrayChildren[j].trainWithDE(x, y,size, K1);
			/*arrayChildren[j].out();
			cout << endl;*/
		}
		forming.replaceGeneration(arrayIndividuals, arrayChildren, numIndividuals);
		findBest();


	}

}
