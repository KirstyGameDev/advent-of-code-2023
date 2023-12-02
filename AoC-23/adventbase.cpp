#include "adventbase.h"

adventbase::adventbase(std::string& folderName)
{
	m_inputFileString = folderName + m_inputSuffix;
	m_testInputFileString = folderName + m_testInputFileString;

}
