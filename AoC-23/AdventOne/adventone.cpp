#include "adventone.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

//#define DBG

void adventone::RunPart1()
{
	ifstream buffer;

	if (GatherInput(buffer))
	{
		for (string temp; getline(buffer, temp);)
		{
#ifdef DBG
			cout << temp << endl;

#endif
			int firstDigit = -1;
			int lastDigit = -1;
			int finalDigit = -1;

			for (int i = 0; i < (temp.length()); i++)
			{
				if (temp[i] >= 48 && temp[i] <= 57)
				{
					if (firstDigit == -1)
					{
						firstDigit = temp[i] - 48;
#ifdef DBG
						cout << "first digit in str = " << firstDigit << endl;
#endif
					}
					else
					{
						lastDigit = temp[i] - 48;
					}
				}
			}

			if (lastDigit == -1)
			{
				lastDigit = firstDigit;
			}

			finalDigit = (firstDigit * 10) + lastDigit;

#ifdef DBG
			cout << "Final digit of the string is " << finalDigit << endl;
#endif
			m_TotalNumbersFromStr.push_back(finalDigit);
		}

		int actualInputTotal = 0;

		// Get the sum of all the numbers from the input
		for (int number : m_TotalNumbersFromStr)
		{
			actualInputTotal += number;
		}

		cout << "Final output : " << actualInputTotal;
	}
	else
	{
		cout << "Unable to locate input file" << endl;
	}


}

bool adventone::GatherInput(ifstream& buffer)
{
	buffer.open("AdventOne/input.txt");
	return buffer.is_open();
}
