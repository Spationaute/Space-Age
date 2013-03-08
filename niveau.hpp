#ifndef NIVEAU_H
#define NIVEAU_H
#include <vector>;
class Niveau{

	public:
		Niveau();
		~Niveau();

		int Load();


	private:
		
		std::vector<char*> titleList;
		char* loadedMap;

};

#endif
