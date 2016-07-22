// RodCutting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "RodCutting.h"
#include<ctime>

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
	const int length = 10;
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
	delete[] p;
	return 0;
}

