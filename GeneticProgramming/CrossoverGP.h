#pragma once
#include <iostream>
#include "Tree.h"
#include <vector>

using namespace std;

class CrossoverGP
{
public:
	Tree getChild(Tree &first,Tree &second);
};

