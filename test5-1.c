/* Skeleton file for LAB5, Problem 1 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STUDENT_NUM 15


struct student {
  char* onoma;
  int am;
  float vathmos;
} students[STUDENT_NUM];


/* Specify return type */
void create_struct_table(char *onoma[STUDENT_NUM], int am[STUDENT_NUM], float vathmos[STUDENT_NUM])
{
	int i;
	for (i=0; i<STUDENT_NUM; i++){
		students[i].onoma = strdup(onoma[i]);		//Check strdup vs strcpy
		students[i].am = am[i];
		students[i].vathmos = vathmos[i];
	}
	return;
}

void show_struct_table()
{
	int i;
	for (i=0; i<STUDENT_NUM; i++){
		printf("%-30s\t%10d%10.1f\n", students[i].onoma, students[i].am, students[i].vathmos);
	}
	return;
}

float compute_average_grade()
{
	int i;
	float average = 0;
	for (i=0; i<STUDENT_NUM; i++){
		average += students[i].vathmos;
	}
	average = average/STUDENT_NUM;
	return average;
}

void print_failed_names()
{
	int i;
	for (i=0; i<STUDENT_NUM; i++){
		if (students[i].vathmos < 10.0){
			printf("%s\n", students[i].onoma);
		}
	}
	return;
}

void change_failed_names()
{
	int i;
	for (i=0; i<STUDENT_NUM; i++){
		if (students[i].vathmos < 10.0){
			students[i].onoma = (char*) realloc(students[i].onoma, strlen(students[i].onoma) + strlen(" (failed)") + sizeof(char));
			strcat(students[i].onoma, " (failed)");
		}
	}
	return;
}

void save_table_in_text_file(){
	int i;
	FILE* fp;
	if ((fp = fopen("table.txt", "a")) == NULL){
		exit(1);
	}
	for (i=0; i<STUDENT_NUM; i++){
		fprintf(fp, "%-30s\t%10d%10.1f\n", students[i].onoma, students[i].am, students[i].vathmos);
	}
	fclose(fp);
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


	create_struct_table(onoma, am, vathmos);
	show_struct_table();
	printf("Average: %f\n", compute_average_grade());
	print_failed_names();
	change_failed_names();
	show_struct_table();
	
	save_table_in_text_file();

	return 0;
}