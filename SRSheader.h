#pragma once

typedef struct Student;

/**
 *
 * Declarations for functions in StudentRecordSystem.cpp
 *
 */
int main();
void welcomeMessage();
int getUserOptionChoice();
int cycleThroughAllRecords(int option);
int chooseStudentRecordById();
void clearBuffer();

/**
*
* Constant declarations
*
 */
#define MIN_CHOICE = 1
#define MAX_CHOICE = 5