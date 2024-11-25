/*
 * data_entry.c
 *
 *  Implement four functions that prompt a student for his/her section,
 *  GPA, course load and credits. Invoke this functions and prints the
 *  information provided on the console.
 */


#include <stdio.h>



// Function prototypes
int get_section();
float get_gpa();
int get_course_load();
int get_credits();



// You can invoke the functions in the main() function as long as the
// prototypes or the implementations are provided before
int
main()
{// Invoke the four functions and print the information on the console
	printf("Section:\t010%d\nCurrent GPA:\t%.2f\nCourses:\t%d\nCredits: \t%d\n", get_section(), get_gpa(), get_course_load(), get_credits());
	return 0;
}



// Function implementations
int
get_section()
{// Prompt the student for his/her section
	printf("Please enter your section number (1, 2, or 3):\n");
	int section;
	scanf("%d", &section);
	return section;
}

float
get_gpa()
{// Prompt the student for his/her GPA
	printf("What is your current GPA?\n");
	float gpa;
	scanf("%f", &gpa);
	return gpa;
}

int
get_course_load()
{// Prompt the student for his/her course load
	printf("How many courses are you taking this semester?\n");
	int load;
	scanf("%d", &load);
	return load;

}

int
get_credits()
{// Prompt the student for the number of credits taken
	printf("How many credits are you taking in total?\n");
	int credits;
	scanf("%d", &credits);
	return credits;
}
