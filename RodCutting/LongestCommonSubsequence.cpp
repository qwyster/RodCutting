#include "stdafx.h"
#include "LongestCommonSubsequence.h"
#include <iostream>

LongestCommonSubsequence::LongestCommonSubsequence(const std::string & inputX, const std::string & inputY):X(inputX),Y(inputY),m(X.length()),n(Y.length())
{
	c = new int*[m+1];
	for (int i = 0; i < m+1; i++) c[i] = new int[n +1];
	b = new char*[m];
	for (int i = 0; i < m; i++) b[i] = new char[n];
}

void LongestCommonSubsequence::lcsLength()
{
	for (int i = 0; i < m+1; i++) c[i][0] = 0;
	for (int j = 0; j < m+1; j++) c[0][j] = 0;
	for (int i = 1; i < m+1; i++)
		for (int j = 1; j < n+1; j++) {
			if (X[i-1] == Y[j-1]) {
				c[i][j] = c[i - 1][j - 1] + 1;
				b[i-1][j-1] = 'd';	// stands for "diagonal"
			}
			else if (c[i - 1][j] >= c[i][j - 1]) {
				c[i][j] = c[i - 1][j];
				b[i-1][j-1] = 't';	// stands for "top"
			}
			else {
				c[i][j] = c[i][j - 1];
				b[i-1][j-1] = 'l'; // stands for "left"
			}
		}
	std::cout << "Maximum-length " << c[m][n] << "\n";
}

void LongestCommonSubsequence::printSolution(int begin, int end) const
{
	if (b[begin-1][end-1] == 'd') {
		printSolution(begin - 1, end - 1);
		std::cout << " " << X[begin-1];
	}
	else if (b[begin-1][end-1] == 't') {
		printSolution(begin - 1, end);
	}
	else if (b[begin - 1][end - 1] == 'l') {
		printSolution(begin, end - 1);
	}
}

LongestCommonSubsequence::~LongestCommonSubsequence()
{
	for (int i = 0; i < m + 1; i++) delete[] c[i];
	delete[] c;
	for (int i = 0; i < m; i++) delete[] b[i];
	delete[] b;
}
