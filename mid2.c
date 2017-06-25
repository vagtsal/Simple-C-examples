/*Άσκηση 2

Δημιουργούμε ένα pipe.
Δημιουργούμε ένα παιδί.
Το παιδί:
	Διαβάζει ένα integer από το πληκτρολόγιο.
	Τον στέλνει στον γονέα.(write(pdf[1], &num,sizeof(int));)
	Όταν δεχτεί 0, τερματίζει.
Ο Γονέας:
	Διαβάζει τον integer (read(pdf[0], &num, sizeof(int));)
	Υπολογίζει τον (xorsum = xorsum ^ num;)
	Όταν κλείνει το pdf[1] από το παιδί΄(δηλ. read() = EOF), 
	περιμένει να κλείσει και το παιδι (waitpid(pid, NULL, 0);
	Τυπώνει τον xorsum και τερματίζει.
*/


#include <stdio.h> //for printf, scanf
#include <unistd.h> //for pipe, fork, write,  read
#include <stdlib.h> //for exit
#include <sys/wait.h> //for waitpid

void main(){
	int pid, pdf[2];
	int num = 1;

	pipe(pdf);

	pid = fork();

	if (pid == 0){									//CHILD***
		close(pdf[0]);
		while (num != 0){
			scanf("%d", &num);
			write(pdf[1], &num, sizeof(int));
		}
		close(pdf[1]);
		exit(1);									//******
	}

	close(pdf[1]);									//PARENT

	int xorsum = 0;
	while (read(pdf[0], &num, sizeof(int)) > 0){
		xorsum = xorsum ^ num;
	}
	close(pdf[0]);
	waitpid(pid, NULL, 0);
	printf("%d\n", xorsum);
	exit(1);										//******
}
