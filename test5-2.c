/* Skeleton file for LAB5, Problem 1 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_NUM 15

typedef struct student {
	char* onoma;
  	int am;
  	float vathmos;
	struct student *next;
} student;

student* head = NULL;


/* Specify return type */
void create_struct_table(char *onoma[STUDENT_NUM], int am[STUDENT_NUM], float vathmos[STUDENT_NUM])
{
	int i;
	student* pr_head = NULL;
	for (i=0; i<STUDENT_NUM; i++){
		head = (student*) malloc (sizeof(student));
		head->onoma = strdup(onoma[i]);				//Check strdup vs strcpy
		head->am = am[i];
		head->vathmos = vathmos[i];
		head->next = pr_head;
		pr_head = head;
	}
	return;
}

void show_struct_table()
{
	student* current = head;
	while (current != NULL){
		printf("%-30s\t%10d%10.1f\n", current->onoma, current->am, current->vathmos);
		current = current->next;
	}
	return;
}


float compute_average_grade()
{
	float average = 0;
	student* current = head;
	while (current != NULL){
		average += current->vathmos;
		current = current->next;
	}
	average = average/STUDENT_NUM;
	return average;
}

void print_failed_names(/* Specify Arguments */)
{
	student* current = head;
	while (current != NULL){
		if (current->vathmos < 10.0){
			printf("%s\n", current->onoma);
		}
		current = current->next;
	}
	return;
}

void change_failed_names(/* Specify Arguments */)
{
	student* current = head;
	while (current != NULL){
		if (current->vathmos < 10.0){
			current->onoma = (char*) realloc(current->onoma, strlen(current->onoma) + strlen(" (failed)") + sizeof(char));
			strcat(current->onoma, " (failed)");
		}
		current = current->next;
	}
	return;
}

int main(void)
{
	char *onoma[] = {
		"Georgios Georgiou", "Vasilios Vasiliou", "Ioanna Ioannidou", 
		"Nikos Nikolaou", "Kiriakos Kiriakidis", "Kwstas Kwstantinidis", 
		"Spyros Spyropoulos", "Dimitris Dimitropoulos", "Dimitra Dimitriadi", 
		"Areti Aretidou", "Ilias Iliopoulos", "Kwstas Kwstoglou",
    "Aimilia Aimilianou", "Xristina Xristopoulou", "Theodoros Theodorou"
	};
    
	int am[] = {
		120, 122, 142, 130, 156, 132, 145, 133, 131, 140, 141, 150, 155, 134, 146
	};

	float vathmos[] = {
		12, 8.5, 15.5, 20, 7.5, 1, 19.5, 12, 17, 17.5, 15.5, 18, 19, 18, 19
	};

	struct employee *head = NULL;

	create_struct_table(onoma, am, vathmos);
	show_struct_table();
	printf("Average: %f\n", compute_average_grade());
	print_failed_names();
	change_failed_names();
	show_struct_table();
	
	return 0;
}