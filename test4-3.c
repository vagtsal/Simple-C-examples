#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>




void main (int argc, char* argv[]){

	char *encrypt(char *str, int dist);
	void decrypt(char *str, int dist);

	if (atoi(argv[2]) > 0 && atoi(argv[2]) <= 26){
		if (strcmp(argv[1], "encrypt") == 0){
			printf("%s\n", encrypt(argv[3], atoi(argv[2])));
		}	
		else if (strcmp(argv[1], "decrypt") == 0){
			decrypt(argv[3], atoi(argv[2]));
			printf("%s\n", argv[3]);
		}
	}
	else {
		exit(-1);
	}
	return;
}



char *encrypt(char *str, int dist){
	char* p = (char*)malloc((strlen(str)+1)*sizeof(char));
	int i = 0;

	for (i = 0; i<=strlen(str); i++){
		if (islower(*(str+i))){
			*(p+i) = (*(str+i)-'a' + dist)%26 + 'a';
		}
		else if (isupper(*(str+i))){
			*(p+i) = (*(str+i)-'A' + dist)%26 + 'A';		
		}
		else {
			*(p+i) = *(str+i);
		}
	}
	return p;	
}

void decrypt(char *str, int dist){
	int i = 0;

	for (i = 0; i<=strlen(str); i++){
		if (islower(*(str+i))){
			*(str+i) = (*(str+i)-'a' - dist + 26)%26 + 'a';
		}
		else if (isupper(*(str+i))){
			*(str+i) = (*(str+i)-'A' - dist + 26)%26 + 'A';	
		}
	}
	return;	
}