#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[]){

	int pdf[2];
	int buf;

	if (pipe(pdf)<0){
		exit(1);
	}
	
	int pid = fork();

	if (pid == 0){
		close(pdf[1]);
		FILE* fp;
		if ((fp = fopen("positive.txt", "w")) < 0){
			exit(1);
		}
		while((read(pdf[0], &buf, sizeof(int)))>=0){
			if (buf == 0){
				fclose(fp);
				exit(1);
			}
			if (buf > 0){
				fprintf(fp, "%d\n", buf);
			}
		}
	
	}
	
	close(pdf[0]);
	while(buf != 0){
		scanf("%d", &buf);
		write(pdf[1], &buf, sizeof(int));
	}
}

