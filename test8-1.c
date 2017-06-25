#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

struct menu {
	char* label;
	char* path;
} menu[6];

void main (int argc, char* argv[]){

	int choice;	
	int ret;
	char* path;

	menu[0].label = "run firefox";
	menu[1].label = "run firefox (and wait)";
	menu[2].label = "run gedit";
	menu[3].label = "run gedit (and wait)";
	menu[4].label = "run gnome-calculator";
	menu[5].label = "run gnome=calculator (and wait)";

	menu[0].path = "firefox";
	menu[1].path = "firefox";
	menu[2].path = "gedit";
	menu[3].path = "gedit";
	menu[4].path = "gnome-calculator";
	menu[5].path = "gnome-calculator";
	
   	while (1){
		printf("Select: \n");
		int i=0;
		for (i=0;i<6;i++){
			printf("%d. %s\n", i+1, menu[i].label);
		}
		printf("0. exit\n");
	
		scanf("%d", &choice);

		if (choice == 0){
			exit(1);
		}
		
		int pid = fork();
		
		if (pid == 0){
			switch (choice){
				case 1:
					execl("/usr/bin/firefox", menu[0].path, NULL);
					break;
				case 2:
					execl("/usr/bin/firefox", menu[1].path, NULL);
					break;
				case 3:
					execl("/usr/bin/gedit", menu[2].path, NULL);	
					break;
				case 4:
					execl("/usr/bin/gedit", menu[3].path, NULL);
					break;
				case 5:
					execl("/usr/bin/gnome-calculator", menu[4].path, NULL);
					break;
				case 6:
					execl("/usr/bin/gnome-calculator", menu[5].path, NULL);
					break;
			}
			//exit(1);
		}		
		
		if (choice == 2 || choice == 4 || choice == 6){
			waitpid(pid, NULL, 0);
		}
		
	}
		
}
