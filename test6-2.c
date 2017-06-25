#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void main (int argc, char* argv[]){
	FILE *pf;
	if ((pf = fopen("data.txt", "r")) == NULL){
		exit(1);
	}
	
	int i = 0;
	int sizes;

	fscanf(pf, "%d", &sizes);
	int* array = (int*)malloc(sizes*sizeof(int));

	for (i=0;i<sizes;i++){
		fscanf(pf, "%d", array+i);
	}

	fclose(pf);

	FILE* pf_n;
	FILE* pf_p;
	if ((pf_n =fopen("negative.txt", "w")) == NULL){
		printf("fisjffsf\n");
		exit(1);
	}
	if ((pf_p =fopen("positive.txt", "w")) == NULL){
		printf("fisjffsf\n");
		exit(1);
	}

	int size_n = 0;
	int size_p = 0;

	fprintf(pf_n, "%d\n", size_n);
	fprintf(pf_p, "%d\n", size_p);

	for (i=0; i<sizes; i++){
		if (*(array+i) >= 0){
			fseek(pf_p, 0, SEEK_END);
			fprintf(pf_p, "%d\n", *(array+i));
			size_p++;
			fseek(pf_p,0,SEEK_SET);
			fprintf(pf_p, "%d", size_p);
		}
		else {
			fseek(pf_n, 0, SEEK_END);
			fprintf(pf_n, "%d\n", *(array+i));
			size_n++;
			fseek(pf_n,0,SEEK_SET);
			fprintf(pf_n, "%d", size_n);
		}
	}

	fclose(pf_n);
	fclose(pf_p);

	int num = 0;
	int sum = 0;

	if ((pf_p = fopen("positive.txt", "r")) == NULL){
		exit(1);
	}

	fscanf(pf_p, "%d", &sizes);
	for (i = 0; i<sizes; i++){
		fscanf(pf_p, "%d", &num);
		sum = sum + num;
	}
	printf("%d", sum);

	fclose(pf_p);
}