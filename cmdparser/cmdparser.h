#pragma once

#include <string>
#include <vector>
#include "../errors/error.h"

class CmdParser{
private:
	int inputFileCount;
	std::vector<std::string> inputFiles;
	std::string outputFile;
	bool debugMode;
	Error e;
public:
	CmdParser(int argc, char const * argv[]);

	// ask these questions after parsing cmdline
	std::vector<std::string> getInputFiles();
	std::string getOutputFile();
	bool isDebugMode();
	
	Error getError(); // returns error code
};