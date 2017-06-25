#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *newstr(char *str){
	int strlength = strlen(str);
	char* dsn = malloc(strlength*sizeof(char));
	strcpy(dsn, str);
	return dsn;
}

void main(){
 	char* sake = "OLE";
 	printf("%d %s\n", sake, sake);
 	char* sake2 = newstr(sake);
 	printf("%d %s\n", sake2, sake2);
}