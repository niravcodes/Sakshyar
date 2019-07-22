#include <iostream>
#include "cmdparser.h"
#include "../errors/error.h"

using namespace std;

int main(int argc, char const *argv[])
{
	CmdParser a(argc, argv);
	cout << (int) a.getError();
	cout << a.getOutputFile();
	for (int i = 0; i < a.getInputFiles().size(); i++)
		cout << a.getInputFiles()[i] << endl;
	return 0;
}