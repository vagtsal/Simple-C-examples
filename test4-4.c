#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[]){
	int n = atoi(argv[1]);
	int* pascal[n];
	int i;
	int j;
	for (i=0;i<n;i++){
		pascal[i] = (int*)malloc(i*sizeof(int));
	}
	for (i=0;i<n;i++){
		for(j=0;j<=i;j++){
			if (i==j || j==0 || i==1){
				*(pascal[i]+j) = 1;
			}
			else {
				*(pascal[i]+j) = *(pascal[i-1]+j) + *(pascal[i-1]+(j-1));
			}
			printf("%d\t", *(pascal[i]+j));
		}
		printf("\n");
	}

	for (i=0;i<n;i++){
		free(pascal[i]);
	}
	return;
}