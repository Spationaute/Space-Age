#include "options.hpp"

Options::Options(){

}

int Options::load(const char* toLoad){
	//Flux de fichier
	int loaded=0;
	fstream optFile;
	optFile.open(toLoad, fstream::in);

	//Expression régulière
	boost::regex optionExpInt("^(\\w+) = (\\d+);");
	boost::regex optionExpDouble("^(\\w+) = (\\d+.\\d+);");
	boost::regex optionExpStr("^(\\w+) = (\\D+);");

	
	//Si le fichier n'existe pas
	//le créé 
	if(!optFile.is_open()){
		
		return -1;
	}else{


		while(!optFile.eof()){
			char temp[64];
			optFile.getline(temp,64); 

			boost::smatch matched;
			string tempstring(temp);	
	
			//Search for Integer option	
			if(boost::regex_search(tempstring, matched, optionExpInt)){
					Option* temp = new Option;
					temp->valueFormat = intValue;
					temp->intValue = atoi(matched[2].str().c_str());
					optionsList.insert(pair<string,Option*>(matched[1],temp));
					loaded++;
			}
			if(boost::regex_search(tempstring, matched, optionExpStr)){
					Option* temp = new Option;
					temp->valueFormat = stringValue;
					temp->stringValue = matched[2].str();
					optionsList.insert(pair<string,Option*>(matched[1],temp));
					loaded++;
			}
			if(boost::regex_search(tempstring, matched, optionExpStr)){
					Option* temp = new Option;
					temp->valueFormat = doubleValue;
					temp->doubleValue = atof(matched[2].str().c_str());
					optionsList.insert(pair<string,Option*>(matched[1],temp));
					loaded++;
			}
		}

		

	}
	return loaded;
}

Option* Options::getOptions(string toGet){
	map<string,Option*>::iterator it;
	it = optionsList.find(toGet);
	if( it == optionsList.end()){
		return NULL;
	}
	return (*it).second;
}

void Options::clear(){
	map<string,Option*>::iterator it;
	for(it=optionsList.begin();it!=optionsList.end();++it){
		delete (*it).second;
	}
	optionsList.clear();
}

Options::~Options(){
	this->clear();
}
