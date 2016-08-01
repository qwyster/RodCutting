// RodCutting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "RodCutting.h"
#include<ctime>
#include <vector>
#include <algorithm>
#include "MatrixChainMultiplication.h"
#include "LongestCommonSubsequence.h"
using namespace std;

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
//int knapsack_value(int n, int* v, int* w, bool* sack, bool* considering, int weightleft,int currentValue) {
//	int i;
//	for (i = 0; i < n; i++) {
//		if (weightleft >= w[i] && considering[i]) {	// if the thief can take a_i
//			considering[i] = false;
//			bool* tmp_considering = new bool[n];
//			std::memcpy(tmp_considering, considering, sizeof(bool)*n);
//			int not_chose_i = knapsack_value(n, v, w, sack, tmp_considering, weightleft, currentValue);
//			std::memcpy(tmp_considering, considering, sizeof(bool)*n);
//			int chose_i =  knapsack_value(n, v, w, sack, tmp_considering, weightleft-w[i], currentValue+v[i]);
//			delete[] tmp_considering;
//			if (chose_i > not_chose_i) {
//				sack[i] = true;
//				return knapsack_value(n, v, w, sack, considering, weightleft - w[i], currentValue + v[i]);
//			}
//			else if (chose_i < not_chose_i){
//				return knapsack_value(n, v, w, sack, considering, weightleft, currentValue);
//			}
//		}
//	}
//	if (i == n) return currentValue;
//}

int knapsack_value(int* v, int* w, int** s, int** reconstruct, int i, int j) {
	if (i == 0 || j == 0) return 0;
	if (s[i - 1][j - 1] != -1) return s[i - 1][j - 1];
	if (j >= w[i - 1]) {
		int chose = knapsack_value(v, w, s, reconstruct, i - 1, j - w[i - 1]) + v[i - 1];
		int notChose = knapsack_value(v, w, s, reconstruct, i - 1, j);
		if (chose > notChose) {
			s[i - 1][j - 1] = chose;
			reconstruct[i - 1][j - 1] = 1;
		}
		else if (chose < notChose) {
			s[i - 1][j - 1] = chose;
			reconstruct[i - 1][j - 1] = 0;
		}
	}
	else {
		s[i - 1][j - 1] = knapsack_value(v,w,s, reconstruct,i-1,j);
		reconstruct[i - 1][j - 1] = 0;
	}
	return s[i - 1][j - 1];
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
	const int W = 50;
	int w[3] = {10,20,30};
	int v[3] = {60,100,120};

	/*const int n = 5;
	const int W = 20;
	int w[n] = { 2,3,4,5,9 };
	int v[n] = { 3,4,5,8,10 };*/
	// naive
	/*bool sack[3];
	bool considering[3];
	for (int i = 0; i < n; i++) {
		sack[i] = false;
		considering[i] = true;
	}
	
	int currentValue = 0;
	std::cout << "Max value = " << knapsack_value(n, v, w, sack, considering, W,currentValue) << std::endl;
	std::cout << "Solution: ";
	for (int i = 0; i < n; i++)
		if (sack[i]) std::cout << i << " ";
	std::cout << std::endl;*/

	int** s;
	int** reconstruct;
	// iterative implementation	
	s = new int*[n+1];
	reconstruct = new int*[n + 1];

	for (int i = 0; i < n+1; i++) {
		s[i] = new int[W+1];
		reconstruct[i] = new int[W + 1];
		memset(s[i], -1, sizeof(int)*(W + 1));
		memset(reconstruct[i], -1, sizeof(int)*(W + 1));
	}
	for (int j = 0; j < W + 1; j++) s[0][j] = 0;
	for (int i = 0; i < n + 1; i++) s[i][0] = 0;
	
	for (int i = 1; i < n+1; i++)
		for (int j = 1; j < W + 1; j++) {
			if (w[i-1] <= j) {
				int chosen = v[i - 1] + s[i - 1][j - w[i - 1]];
				int notChosen = s[i - 1][j];
				if (chosen > notChosen) {
					s[i][j] = chosen;
					reconstruct[i][j] = 1;
				}
				else if (chosen < notChosen){
					s[i][j] = s[i - 1][j];
					reconstruct[i][j] = 0;
				}
			}
			else {
				s[i][j] = s[i - 1][j];
				reconstruct[i][j] = 0;
			}
	}
	cout << "max value = " << s[n][W] << endl;
	cout << "Solution: ";
	int i = n;
	int j = W;
	while (s[i][j] > 0) {
		if (reconstruct[i][j] == 1) {
			cout << "A" << i << " ";
			j -= w[i - 1];
			i--;
		}
		else {
			i--;
		}
	}
	cout << endl;
	for (int i = 0; i < n+1; i++) {
		delete[] s[i];
		delete[] reconstruct[i];
	}
	delete[] reconstruct;
	delete[] s;

	//s = new int*[n];
	//reconstruct = new int*[n];	// reconstruct[i][j] = 1 if A_i is chosen, = 0 otherwise

	//for (int i = 0; i < n; i++) {
	//	s[i] = new int[W];
	//	reconstruct[i] = new int[W];
	//	memset(reconstruct[i], -1, sizeof(int)*W);
	//	memset(s[i], -1, sizeof(int)*W);
	//}
	//cout << "max value = " << knapsack_value(v, w, s, reconstruct, n, W) << endl;
	//// reconstruct a solution
	//cout << "Optimal solution: ";
	//int i = n-1;
	//int j = W-1;
	//int weight = W;
	//while (i >=0 && j>=0) {
	//	if (reconstruct[i][j] == 1) {
	//		cout << "A" << i + 1 << " ";
	//		weight -= w[i];
	//		j -= w[i];
	//		i--;
	//	}
	//	else {
	//		i--;
	//	}
	//}
	//cout << endl;

	//for (int i = 0; i < n; i++) {
	//	delete[] s[i];
	//	delete[] reconstruct[i];
	//}
	//delete[] s;
	//delete[] reconstruct;
	return 0;
}

