// RodCutting.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include "RodCutting.h"
#include<ctime>

int main()
{
	

	RodCutting rc;
	int length = 10;
	
	clock_t begin1 = clock();
	std::cout << "Maximal preis for cutting a rod of length " << length << " is " << rc.doRodCutting(length) << "\n";
	clock_t end1 = clock();
	
	clock_t begin2 = clock();
	std::cout << "Maximal preis for cutting a rod of length " << length << " is " << rc.doRodCuttingMemoization(length) << "\n";
	clock_t end2 = clock();
	
	std::cout << "Elapsed time:\n";
	std::cout << "Naive: " << double(end1 - begin1) / CLOCKS_PER_SEC << "\n";
	std::cout << "Memoization: " << double(end2 - begin2) / CLOCKS_PER_SEC << "\n";
	std::cin.get();
    return 0;
}

