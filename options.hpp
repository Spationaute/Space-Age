#ifndef OPTION_H
#define OPTION_H
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <boost/regex.hpp>

using namespace std;

enum format{
	intValue,
	stringValue,
	doubleValue
};

struct Option{
	format valueFormat;
	int intValue;
	string stringValue;
	double doubleValue;
};

class Options{

	public:
		Options();
		~Options();
	
		int load(const char* toLoad);	
		Option* getOptions(string toGet);
		void clear();
	

	private:
		Option options;
		map<string,Option*> optionsList;


};

#endif
