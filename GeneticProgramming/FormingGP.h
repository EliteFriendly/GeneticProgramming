#pragma once
#pragma once
#include <iostream>
#include<vector>
#include<functional>
#include "MutationGP.h"
#include"CrossoverGP.h"
#include"Tree.h"
class FormingGP
{
public:
	void replaceGeneration(vector<Tree>& arrIndividuals, vector<Tree>& arrChildren);

};

