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
	selection = new RankedSelection;
	crossover = new OnepointCrossover;

	GeneticProgramming::numIndividuals = numIndividuals;
	GeneticProgramming::numGeneration = numGeneration;
	arrayIndividuals = new Tree[numIndividuals];
	arrayChildren = new Tree[numIndividuals];
	//Первая иницилизация поколения
	for (int i = 0; i < numIndividuals; i++) {
		Tree t(treeDepth-1,ammInputs);
		//Подсчет узлов и уровней
		int nodes = 0, lvl = 0;
		t.recountLayers(lvl);
		t.countNodes(nodes);

		arrayIndividuals[i] = t;
		arrayIndividuals[i].trainWithDE(x, y,size, K1);
	}

	findBest();//Первый поиск лучшего индивида
	//Основное начало алгоритма
	int numParent1, numParent2;

	for (int i = 0; i < numGeneration; i++) {
		cout << "Номер генерации = " << i << endl;
		selection->setArrIndividuals(arrayIndividuals, numIndividuals);
		for (int j = 0; j < numIndividuals; j++) {
			
			numParent1 = selection->getNumParents();
			numParent2 = selection->getNumParents();
			while (numParent1 == numParent2) {
				numParent2 = selection->getNumParents();
			}
			
			arrayChildren[j] = crossover->getChild(arrayIndividuals[numParent1], arrayIndividuals[numParent2]);
			mutation->doMutChild(arrayChildren[j]);

			

			arrayChildren[j].trainWithDE(x, y,size, K1);
			/*arrayChildren[j].out();
			cout << endl;*/
		}
		forming.replaceGeneration(arrayIndividuals, arrayChildren, numIndividuals);
		findBest();


	}

}
