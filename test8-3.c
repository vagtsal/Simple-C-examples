#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>

void main (int argc, char* argv[]){
	int pdf[2];
	char buf[50];
	

	if (pipe(pdf) < 0){
		exit(1);
	}

	int pid = fork();
	
	if (pid == 0){
		close(pdf[1]);
		
		dup2(pdf[0],STDIN_FILENO);
		execl("/usr/bin/gnuplot", "gnuplot", NULL);
	}
	
	while(strcmp(buf,"exit\n") != 0){
		fgets(buf,50, stdin);
		write(pdf[1], buf, strlen(buf));
	}
}
