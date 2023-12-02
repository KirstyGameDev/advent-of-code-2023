#include "../utils.h"
#include <iostream>
#include <string>
#include "adventtwo.h"
using namespace std;

//#define DBG

void adventtwo::SolvePartOne()
{
	fstream buffer;
	if (Utils::GatherInput(buffer, m_inputFile))
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
					if (newString.find ("blue") == 0)
					{
						currentBlueTotal += tempNumber;
					}
					else if (newString.find ("red") == 0 )
					{
						currentRedTotal += tempNumber;
					}
					else if (newString.find("green") == 0)
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
					if (newString.find(";") == 0)
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
	fstream buffer;
	if (Utils::GatherInput(buffer, "AdventTwo/input.txt"))
	{

		int gameId = 1;


		for (string line; getline(buffer, line);)
		{
			int currentMaxBlue = 0;
			int currentMaxRed = 0;
			int currentMaxGreen = 0;

			size_t pos = line.find(":");
			line.erase(0, pos + 2);				// Remove the 'Game xx : ' from the string
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

					if (newString.find("blue") == 0)
					{
						if (tempNumber > currentMaxBlue)
						{
							currentMaxBlue = tempNumber;
						}
					}
					else if (newString.find("red") == 0)
					{
						if (tempNumber > currentMaxRed)
						{
							currentMaxRed = tempNumber;
						}
					}
					else if (newString.find("green") == 0)
					{
						if (tempNumber > currentMaxGreen)
						{
							currentMaxGreen = tempNumber;
						}
					}
				}
			}

			int gamePower = currentMaxRed * currentMaxGreen * currentMaxBlue;

			m_gamePowers.push_back(gamePower);
		}

		int sumOfPowers = 0;
		for (int power : m_gamePowers)
		{
			sumOfPowers += power;
		}

		cout << "Total is " << sumOfPowers << endl;
	}
	else
	{
		cout << "Trouble opening the file" << endl;
	}

}

