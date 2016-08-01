#include "stdafx.h"
#include "MatrixChainMultiplication.h"
#include <iostream>

MatrixChainMultiplication::MatrixChainMultiplication(int length, std::vector<std::pair<int, int>> p_input) :n(length), p(p_input)
{
	m = new int*[n];
	s = new int*[n - 1];
	int i, j, k, l;
	int cost;
	for (i = 0; i < n; i++) m[i] = new int[n] {0};
	/*std::cout << "Cost init\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j < i) std::cout << "-\t";
			else std::cout << m[i][j] << "\t";
		}
		std::cout << std::endl;
	}*/
	for (i = 0; i < n - 1; i++) s[i] = new int[n - 1]{ 0 };

	for (l = 2; l <= n; l++) {
		for (i = 1; i <= n - l + 1; i++) {
			j = l + i - 1;
			m[i - 1][j - 1] = INT_MAX;
			for (k = i; k < j; k++) {
				cost = m[i - 1][k - 1] + m[k][j - 1] + p[i - 1].first*p[k - 1].second*p[j - 1].second;
				if (cost < m[i - 1][j - 1]) {
					m[i - 1][j - 1] = cost;
					s[i - 1][j - 2] = k;
				}
			}
		}
	}
	std::cout << "min cost = " << m[0][length - 1] << "\n";
	/*std::cout << "Cut\n";
	for (int i = 1; i < n; i++) {
		for (int j = 2; j <= n; j++) {
			std::cout << s[i - 1][j - 2] << "\t";
		}
		std::cout << std::endl;
	}*/
}

MatrixChainMultiplication::~MatrixChainMultiplication()
{
	for (int i = 0; i < n; i++)
		delete[] m[i];
	delete[] m;
}

void MatrixChainMultiplication::printSolution(int begin, int end) const
{
	if (begin == end) std::cout << "A" << begin;
	else {
		std::cout << "(";
		printSolution(begin, s[begin - 1][end - 2]);
		printSolution(s[begin - 1][end - 2] + 1, end);
		std::cout << ")";
	}
}
