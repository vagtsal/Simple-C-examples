/* Ασκηση 1

2 αρχεία, ενα bin, ενα txt.
Ανοιγουμε το bin, πηγαίνουμε στον χαρακτήρα 353 πριν το τέλος
Το διαβάζουμε.
Κλείνουμε το bin.
Τυπώνουμε τον χαρακτήρα.
Ανοιγουμε το txt.
Διαβάζουμε ένα ένα χαρακτήρες.
Αν ισούται με αυτόν του bin, αυξάνουμε τον counter.
Τυπώνουμε τον counter.
*/



#include <stdio.h>			//for printf
#include <stdlib.h>			//for exit
#include <unistd.h>			//for open, write
#include <fcntl.h>			//for O_RDONLY	

void main(){
	
	char buf = 'a';
	int bp = open("a.bin", O_RDONLY);

	lseek(bp, -11, SEEK_END);
	read(bp, &buf, 1);

	close(bp);

	printf("%c\n", buf);

	FILE* fp = fopen("b.txt", "r");

	char cur;
	int counter = 0;
	while (fscanf(fp, "%c", &cur) != EOF){
		if (cur == buf){
			counter++;
		}
	}

	fclose(fp);

	printf("%d\n", counter);
	exit(1);
}
