/**
* @author: ChrisMTucson
*
* Purpose: This is a console-based student record system.
* The idea is to create a system of record in which you
* can create new students, read data about existing students,
* update student data, and destroy records.
*
* Rather than a true database, data is stored in a .txt file
*
* Updated: 2022-04-01
*
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SRSheader.h"

struct Student {
	int id;
	char firstName[50];
	char lastName[50];
	float gpa;
	int numCredits;
	int nextStudentId;
};

int main() {

	int optionChoice = -1;

	// print welcome message
	welcomeMessage();


	// get user choice for operation
	optionChoice = getUserOptionChoice();

	// TO DO:
	// Conditional logic to lead to functions:
	// 2. Open and view individual student records (branch several search options)
	// 3. Create new student record and append to file
	// 4. Update student record and append to file
	// 5. Delete student record
	//

	switch (optionChoice) {
	case 1:
		printf("Displaying all available records:\n");
		int numLines = cycleThroughAllRecords(1);
		// TEST: logic behind line count
		printf("Num Lines: %d\n", numLines);
		break;
	default:
		printf("Goodbye.\n");
		break;
	}


	return EXIT_SUCCESS;
}


/**
 *
 * Function: welcomeMessage()
 * @params: none
 * @return: none
 *
 * Purpose: prints message to console
 *
 */
void welcomeMessage() {
	printf("**************************************************************************\n");
	printf("*****                                                                *****\n");
	printf("*****                                                                *****\n");
	printf("*****           Welcome to the Student Record System!                *****\n");
	printf("*****                                                                *****\n");
	printf("*****                                                                *****\n");
	printf("**************************************************************************\n");
	return;
}

/**
 *
 * Function: getUserOptionChoice()
 * @params: none
 * @return: int choice (the user's choice)
 *
 * Purpose: gets user input to call correct function
 *
 */
int getUserOptionChoice() {
	int choice = -1;
	int invalidChoice = choice < 1 || choice > 5;

	while (invalidChoice) {
		printf("Options:\n\n");
		printf("1. View all student records.\n");
		printf("2. View single student record.\n");
		printf("3. Create new student record.\n");
		printf("4. Update existing student record.\n");
		printf("5. Delete student record. DANGER: THIS ACTION CANNOT BE UNDONE!\n\n");
		printf("Please type the number of the option you choose:\n");
		scanf_s("%d", &choice);
		
		invalidChoice = choice < 1 || choice > 5;

		// catch bad type input
		if (invalidChoice) {
			printf("\nSorry, I did not recognize your choice. Please enter a valid integer between 1 and 5.\n");
			// clearing buffer
			int ch;
			while ((ch = getchar()) != '\n');
		}
	}
	printf("\n");

	return choice;
}


/**
 *
 * Function: cycleThroughAllRecords()
 * @params: int option (1 = display all records)
 * @return: int numLines (number of lines in the file)
 * 
 * purpose: Cycles through file
 */

int cycleThroughAllRecords(int option) {

	FILE* f;
	int errorCode = fopen_s(&f, "studentrecords.txt", "r");
	int numLines = 0;

	if (errorCode != 0) {
		printf("No records to display.\n");
	}
	else {
		char c[150];
		while (fgets(c, 150, f) != NULL) {

			if (option == 1) {
				printf("%s", c);
			}
			numLines++;
		}
	}

	printf("\n");

	return numLines;
}