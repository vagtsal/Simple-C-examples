#include <stdio.h>
#include <stdarg.h>

void myprint(int n, ...){
	va_list args;

	char type;
	
	va_start(args,n);
	int i;
	for (i=0; i<n; i++){
		type = va_arg(args, int);
		if (type == 'd'){
			printf("%d\n", va_arg(args,int));
		}
		if (type == 'f'){
			printf("%f\n", va_arg(args,double));
		}
	}

	va_end(args);
}

void main(int argc, char* argv[]){
	myprint(3,'d', 5,'f',42.2, 'f', 432.3);
}