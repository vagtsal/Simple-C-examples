#include <stdio.h>

void printbin(int n){
	int i;
	for (i=31; i>=0;i--){
		printf("%d", (n>>i) & 1);
	}
	printf("\n");
}

void main(int argc, char* argv[]){
	printbin(7657543);
}