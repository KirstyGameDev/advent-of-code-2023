#pragma once
#include <fstream>
#include <vector>
using namespace std;

class adventtwo
{

public:
	void SolvePartOne();

	void SolvePartTwo();


private:

	vector<int> m_validGameIds;
	vector<int> m_gamePowers;
	const int m_maxBlues = 14;
	const int m_maxGreens = 13;
	const int m_maxResd = 12;
	const string m_inputFile = "AdventTwo/input.txt";
	const string m_testInputFile = "AdventTwo/testinput.txt";

};

