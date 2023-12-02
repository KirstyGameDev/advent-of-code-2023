#pragma once
#include <string>
#include <sstream>
#include <vector>

class adventone
{
public : 
	void RunPart1();

	void RunPart2();


private : 

	//std::stringstream buffer;
	std::string inputString;
	const std::string inputFile = "AdventOne/input.txt";
	const std::string testInputFile = "AdventOne/textinput.txt";

	std::vector<int> m_TotalNumbersFromStr;
};

