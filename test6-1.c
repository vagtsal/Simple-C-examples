#include <stdio.h>

unsigned int reverse_endian(int num){
	int num1 = num & (255<<24);
	int num2 = num & (255<<16);
	int num3 = num & (255<<8);
	int num4 = num & (255);

	num1 = num1>>24;
	num2 = num2>>8;
	num3 = num3<<8;
	num4 = num4<<24;

	num = num1 |  num2 |  num3 | num4;
	return num;
}

void main(int argc, char* argv[]){
	int num = -670957568;
	printf("%d\n", reverse_endian (num));
}
