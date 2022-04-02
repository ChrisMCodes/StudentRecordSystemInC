#pragma once

typedef struct Student;

/**
 *
 * Declarations for functions in StudentRecordSystem.cpp
 *
 */

void welcomeMessage();
int getUserOptionChoice();
int cycleThroughAllRecords(int option);

/**
*
* Constant declarations
*
 */
#define MIN_CHOICE = 1
#define MAX_CHOICE = 5