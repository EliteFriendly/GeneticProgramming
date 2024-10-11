#include "GeneticProgramming.h"

void GeneticProgramming::findBest()
{
	for (int i = 0; i < numIndividuals; i++) {
		if (arrayIndividuals[i].getFitness() > bestIndividual.getFitness()) {
			bestIndividual = arrayIndividuals[i];
		}
	}
}

void GeneticProgramming::startTrain(vector<double> x, vector<double> y, int numIndividuals, int numGeneration)
{
	GeneticProgramming::numIndividuals = numIndividuals;
	GeneticProgramming::numGeneration = numGeneration;
	arrayIndividuals.resize(numIndividuals);
	arrayChildren.resize(numIndividuals);
	//Первая иницилизация поколения
	for (int i = 0; i < numIndividuals; i++) {
		Tree t(treeDepth);
		arrayIndividuals[i] = t;
		arrayIndividuals[i].trainWithDE(x, y, K1);
	}

	findBest();//Первый поиск лучшего индивида
	//Основное начало алгоритма
	int numParent1, numParent2;

	for (int i = 0; i < numGeneration; i++) {
		cout << "Номер генерации = " << i << endl;
		for (int j = 0; j < numIndividuals; j++) {
			numParent1 = selection.getNumParents(arrayIndividuals);
			numParent2 = selection.getNumParents(arrayIndividuals);
			while (numParent1 == numParent2) {
				numParent2 = selection.getNumParents(arrayIndividuals);
			}
			arrayChildren[j] = crossover.getChild(arrayIndividuals[numParent1], arrayIndividuals[numParent2]);
			mutation.getMutChild(arrayChildren[j]);

			arrayChildren[j].trainWithDE(x, y, K1);
			/*arrayChildren[j].out();
			cout << endl;*/
		}
		forming.replaceGeneration(arrayIndividuals, arrayChildren);
		findBest();


	}

}
