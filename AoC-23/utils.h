#include <string>
#include<fstream>
#include <vector>
using namespace std;

class Utils
{
public:
	static bool GatherInput(fstream& buffer, string file)
	{
		buffer.open(file);
		return buffer.is_open();
	}

	static size_t SplitString(const string& txt, vector<string>& stringVector, char splitAtChar)
	{
        size_t pos = txt.find(splitAtChar);
        size_t initialPos = 0;
        stringVector.clear();

        // Decompose statement
        while (pos != std::string::npos) {
            stringVector.push_back(txt.substr(initialPos, pos - initialPos));
            initialPos = pos + 1;

            pos = txt.find(splitAtChar, initialPos);
        }

        // Add the last one
        stringVector.push_back(txt.substr(initialPos, std::min(pos, txt.size()) - initialPos + 1));

        return stringVector.size();
	}
};

