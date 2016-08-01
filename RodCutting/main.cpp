// RodCutting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "RodCutting.h"
#include<ctime>
#include <vector>
#include "MatrixChainMultiplication.h"
#include "LongestCommonSubsequence.h"
/*
	Solve the rod cutting problem for a rod of length l.
	Return the highest price.
*/
int rodCutting(int* p, int length, int l, int* cutSeq) {
	int result;
	int* optimal = new int[length];
	for (int k = 1; k <= l; k++) {
		// find optimal[k]
		optimal[k-1] = p[k-1];
		cutSeq[k - 1] = k;
		for (int i = 1; i <= k - 1; i++) {
			int newPrice = p[i - 1] + optimal[k - i - 1];
			if (newPrice > optimal[k-1]) {
				cutSeq[k - 1] = i;
				optimal[k-1] = newPrice;
			}
		}
	}
	result = optimal[l-1];
	delete[] optimal;
	return result;
}

/*
	Naive implementation. O(2^n).
*/
int knapsack_value(int n, int* v, int* w, bool* sack, bool* considering, int weightleft,int currentValue) {
	int i;
	for (i = 0; i < n; i++) {
		if (weightleft >= w[i] && considering[i]) {	// if the thief can take a_i
			considering[i] = false;
			bool* tmp_considering = new bool[n];
			std::memcpy(tmp_considering, considering, sizeof(bool)*n);
			int not_chose_i = knapsack_value(n, v, w, sack, tmp_considering, weightleft, currentValue);
			std::memcpy(tmp_considering, considering, sizeof(bool)*n);
			int chose_i =  knapsack_value(n, v, w, sack, tmp_considering, weightleft-w[i], currentValue+v[i]);
			delete[] tmp_considering;
			if (chose_i > not_chose_i) {
				sack[i] = true;
				return knapsack_value(n, v, w, sack, considering, weightleft - w[i], currentValue + v[i]);
			}
			else if (chose_i < not_chose_i){
				return knapsack_value(n, v, w, sack, considering, weightleft, currentValue);
			}
		}
	}
	if (i == n) return currentValue;
}


int main()
{
	/*RodCutting rc;
	int length = 8;
	
	clock_t begin1 = clock();
	std::cout << "Maximal preis for cutting a rod of length " << length << " is " << rc.doRodCutting(length) << "\n";
	clock_t end1 = clock();
	
	clock_t begin2 = clock();
	std::cout << "Maximal preis for cutting a rod of length " << length << " is " << rc.doRodCuttingMemoization(length) << "\n";
	clock_t end2 = clock();
	
	std::cout << "Elapsed time:\n";
	std::cout << "Naive: " << double(end1 - begin1) / CLOCKS_PER_SEC << "\n";
	std::cout << "Memoization: " << double(end2 - begin2) / CLOCKS_PER_SEC << "\n";
	int* s = new int[length];
	std::cout << "Maximal preis for cutting a rod of length " << length << " is " << rc.doRodCuttingBottomUp(length,s) << "\n";
	std::cout << "Solution: ";
	int n = length;
	while (n > 0) {
		std::cout << s[n-1] << " ";
		n = n - s[n-1];
	}
	delete[] s;
	std::cout << std::endl;
	std::cin.get();*/
	/*const int length = 10;
	int* p = new int[length] {1,5,8,9,10,17,17,20,24,30};
	int* cutSeq = new int[length];
	cutSeq[0] = 1;
	int l = 8;
	std::cout << "Optimal value of cutting a rod of length " << l << " is " << rodCutting(p,length,l,cutSeq) << std::endl;
	std::cout << "Solution to this problem: ";
	int r = l;
	while (r > 0) {
		std::cout << cutSeq[r-1] << " ";
		r -= cutSeq[r - 1];
	}
	std::cout << std::endl;
	delete[] cutSeq;
	delete[] p;*/
	/*std::vector<std::pair<int, int>> input;
	input.push_back(std::pair<int, int>(30,35));
	input.push_back(std::pair<int, int>(35,15));
	input.push_back(std::pair<int, int>(15,5));
	input.push_back(std::pair<int, int>(5,10));
	input.push_back(std::pair<int, int>(10,20));
	input.push_back(std::pair<int, int>(20,25));
	int length = input.size();
	MatrixChainMultiplication mcm(length, input);
	mcm.printSolution(1, length);
	std::cout << std::endl;*/

	//std::string X("ACCGGTCGAGTGCGCGGAAGCCGGCCGAA");
	//std::string Y("GTCGTTCGGAATGCCGTTGCTCTGTAAA");
	///*std::string X("ABCBDAB");
	//std::string Y("BDCABA");*/
	//LongestCommonSubsequence lcb(X, Y);
	//lcb.lcsLength();
	//lcb.printSolution(X.length(), Y.length());
	//std::cout << "\n";

	const int n = 3;
	int w[3] = {10,20,30};
	int v[3] = {60,100,120};
	bool sack[3];
	bool considering[3];
	for (int i = 0; i < n; i++) {
		sack[i] = false;
		considering[i] = true;
	}
	int W = 50;
	int currentValue = 0;
	std::cout << "Max value = " << knapsack_value(n, v, w, sack, considering, W,currentValue) << std::endl;
	std::cout << "Solution: ";
	for (int i = 0; i < n; i++)
		if (sack[i]) std::cout << i << " ";
	std::cout << std::endl;
	return 0;
}

