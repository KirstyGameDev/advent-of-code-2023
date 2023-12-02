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
	bool GatherInput(std::ifstream& buffer);			// returns if successful

	//std::stringstream buffer;
	std::string inputString;

	std::vector<int> m_TotalNumbersFromStr;
};

