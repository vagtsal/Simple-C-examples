#include <stdio.h>
#include <stdlib.h>

void main(int argc, char* argv[]){
	float result = 0;
	int index = 0;
	int i;

	char telestis = *argv[1];
	int array[argc-2];

	for ( i = 2; i<argc; i++){
		array[index] = atoi(argv[i]);
		index++;
	}
	
	switch (telestis){
		case '+':
			result = array[0];
			for ( i=1; i<index; i++){
				
				result = result + array[i];
			}
			break;
		case '-':
			result = array[0];
			for ( i=1; i<index; i++){
				result -= array[i];
			}
			break;
		case '*':
			result = array[0];
			for ( i=1; i<index; i++){
				result = result * array[i];
			}
			break;
		case '/':
			result = array[0];
			for ( i=1; i<index; i++){
				result = result / array[i];
			}
			break;
		default:
			printf("Wrong telestis!");
			return;
	}

	printf("%f\n", result);
	return;
}
