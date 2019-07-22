#include "cmdparser.h"
#include <iostream>

CmdParser::CmdParser(int argc, char const * argv[]){
	enum eFlag{InputFileMode, OutputFileMode} flag;

	//Initial values
	flag = InputFileMode;
	debugMode = false;
	e = Error::noError;
	//end Initial values


	int argumentCount = argc - 1;
	int argumentIndex = 1;
	for (; argumentIndex <= argumentCount; argumentIndex++){
		std::string arg(argv[argumentIndex]);

		// Output file 
		if (arg == "-o"){
			//todo make this work sammelan
			if (argumentIndex-2 == argumentCount){
				e = Error::noOutputFileSpecified;
				break;
			}
			else {
				flag = OutputFileMode;
				continue;
			}
		}
		else if (arg == "-d"){
			debugMode = true;
			continue;
		}
		

		if (flag == InputFileMode)
			inputFiles.push_back(arg);
		else if (flag == OutputFileMode){
			outputFile = arg;
			flag = InputFileMode;
		}
	}
}









// -------- GETTERS -----------

std::string CmdParser::getOutputFile(){
	return outputFile;
}

Error CmdParser::getError(){
	return e;
}

std::vector<std::string> CmdParser::getInputFiles(){
	return inputFiles;
}

// ---------GETTERS end _-------