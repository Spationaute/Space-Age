#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <errno.h>

typedef unsigned int  uint;

struct header{
	int nombre;
	int* size;
	char** data;
}head;

int main(int args,char* argv[]){
	//Pressing png to make a one time loadable sprite for
	//the game
	uint flag=0x0;
	int option = 0;	
	while( option != -1 ){
		option = getopt(args,argv,"ad:");
		switch(option){
			case 'a':
				flag = flag^0x01;		
				break;
			case 'd':
				flag = flag^0x02;
				break;
		}
	}
	
	if(flag & 0x01){
		printf("Assemblage: \n");

		int nbrFile = args-optind;
		char** fichiers = (char**) malloc(nbrFile*sizeof(char*));
		head.size = (int*) malloc(nbrFile*sizeof(int));

		int i=0;
		for(i=optind;i<args;++i){
			
			fichiers[i]=argv[i];
			printf("\t%s: ",fichiers[i]);

			FILE* temp = fopen(fichiers[i],"r");
		
			
			if(temp==NULL){
				printf("échec, erreur: %i\n",errno);
				--nbrFile;
			}else{
				fseek(temp,0,SEEK_END);
				int tempsize = ftell(temp);
				rewind(temp);

				head.nombre = nbrFile;
				head.size[i]=tempsize///to change
	
				char* tempdata = (char*) malloc(tempsize*sizeof(char));
				fread(tempdata,sizeof(char),tempsize,temp);
				head.data[i]=tempdata;

				printf(" Ok\n");
			}
//Bug !?			fclose(temp);
		}

		FILE* writeto = fopen("press.ppn","w");
		fwrite(&head,1,sizeof(head),writeto);
		fclose(writeto);		
		printf("PNG stack created: %i images stacked\n",head.nombre);
	}
	return 0;
}
