#include "adventtwo.h"

#include "../utils.h"
#include <iostream>
#include <string>
using namespace std;

//#define DBG

void adventtwo::SolvePartOne()
{
	fstream buffer;
	if (Utils::GatherInput(buffer, "AdventTwo/input.txt"))
	{

		int gameId = 1;
		

		for (string line; getline(buffer, line);)
		{
			int currentBlueTotal = 0;
			int currentRedTotal = 0;
			int currentGreenTotal = 0;

			size_t pos = line.find(":");
			line.erase(0, pos+2);				// Remove the 'Game xx : ' from the string
#ifdef DBG
			cout << line << endl;
#endif
			vector<string> splitOutString;
			Utils::SplitString(line, splitOutString, ' ');

			int tempNumber = 0;
			bool isValid = true;

			for (string newString : splitOutString)
			{
#ifdef DBG
				cout << newString << endl;
#endif
				const char* tempString = newString.c_str();
				int numCheck = 0;
				if (numCheck = std::atoi(tempString) > 0)
				{
					// lets assume we have a number
					tempNumber = stoi(newString);
				}
				else
				{
					if (newString == "blue," || newString == "blue;")
					{
						currentBlueTotal += tempNumber;
					}
					else if (newString == "red," || newString == "red;")
					{
						currentRedTotal += tempNumber;
					}
					else if (newString == "green," || newString == "green;")
					{
						currentGreenTotal += tempNumber;
					}


					if (currentBlueTotal > m_maxBlues
						|| currentGreenTotal > m_maxGreens
						|| currentRedTotal > m_maxResd)
					{
						isValid = false;
#ifdef DBG
						cout << "found invalid game" << endl;
#endif
						break;
					}

					// detect if we're starting a new set 
					if (newString.find(";"))
					{
						currentBlueTotal = 0;
						currentRedTotal = 0;
						currentGreenTotal = 0;
					}
				}
			}

			if (isValid)
			{
				m_validGameIds.push_back(gameId);
#ifdef DBG
				cout << "valid game found at " << gameId << endl;
#endif
			}

			gameId++;
		}

		int sumOfGameIds = 0;
		for (int gameId : m_validGameIds)
		{
			sumOfGameIds += gameId;
		}

		cout << "Total is " << sumOfGameIds << endl;
	}
	else
	{
		cout << "Trouble opening the file" << endl;
	}
}

void adventtwo::SolvePartTwo()
{
}

