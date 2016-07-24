#pragma once
#include <string>

class LongestCommonSubsequence
{
public:
	LongestCommonSubsequence(const std::string&,const std::string&);
	void lcsLength();
	void printSolution(int begin, int end) const;
	~LongestCommonSubsequence();

private:
	std::string X;
	std::string Y;
	int m;
	int n;
	int** c;
	char** b;
};

