#include "FormingGP.h"

void FormingGP::replaceGeneration(vector<Tree>& arrIndividuals, vector<Tree>& arrChildren)
{
	int individuals = arrIndividuals.size();

	for (int i = 0; i < individuals; i++) {
		for (int j = 0; j < individuals; j++) {

			if (arrIndividuals[i].getFitness() < arrChildren[j].getFitness()) {
				arrIndividuals[i] = arrChildren[j];
				arrChildren[j] = Tree();
				break;
			}

		}
	}
}
