#pragma once
#include <string>
using namespace std;

class adventbase
{
public : 
	adventbase(std::string& folderName);

	virtual void SolvePartOne() {}
	virtual void SolvePartTwo() {}

protected : 
	string m_inputFileString;
	string m_testInputFileString;

	const string m_inputSuffix = "/input.txt";
	const string m_testInputSuffix = "/testinput.txt";
};

