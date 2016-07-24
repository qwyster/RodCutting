#pragma once
#include <vector>

class MatrixChainMultiplication
{
public:
	MatrixChainMultiplication(int,std::vector<std::pair<int,int>>);
	~MatrixChainMultiplication();
	void printSolution(int begin,int end) const;

private:
	std::vector<std::pair<int, int>> p;
	int** m;
	int** s;
	int n;
};

