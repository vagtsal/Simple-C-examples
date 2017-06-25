#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

void main(int argc, char* argv[]){
	char* path = argv[1];
	int fd;
	unsigned char verify[] = {137, 80, 78, 71, 13, 10, 26, 10}; 
	unsigned char buf;
	int dim = 0;

	if ((fd = open(path, O_RDONLY)) < 0){
		perror("");
		exit(0);
	}
	int i;
	for (i=0; i<8; i++){
		read(fd, &buf, 1);
		if (buf != verify[i]){
			printf("File is not png\n");
		}
	}
	printf("File is png!\n");
	
	for (i=0; i<8; i++){
		read(fd, &buf, 1);
	}
	
	for (i=0;i<4;i++){
		read(fd, &buf, 1);
		dim = (dim<<8) | buf;
	}
	printf("Width: %d\n", dim);
	
	for (i=0;i<4;i++){
		read(fd, &buf, 1);
		dim = (dim<<8) | buf;
	}
	printf("Height: %d\n", dim);

	read(fd, &buf, 1);

	read(fd, &buf, 1);
	printf("%d\n", buf);
	if ((buf&(1<<1))>>1 == 1) {
		printf("Image is colored\n");
	}
	else{
		printf("Image is black and white\n");
	}
	
	if ((buf&(1<<2))>>2 == 1) {
		printf("Image is layered\n");
	}
	else{
		printf("Image is not layered\n");
	}

	
	close(fd);
}
