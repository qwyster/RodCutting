#pragma once
class RodCutting
{
private:
	int* r;
	int* p;
public:
	const static int LENGTH = 10;
	RodCutting();
	~RodCutting();
	int doRodCutting(int);
	int doRodCuttingMemoization(int);
	int doRodCuttingBottomUp(int,int*);
};

