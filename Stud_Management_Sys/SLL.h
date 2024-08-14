/*
 * SLL.h
 *
 *  Created on: Aug 14, 2024
 *      Author: hp
 */

#ifndef SLL_H_
#define SLL_H_

extern struct Student;
struct node;

// Function prototypes

// Function to create a new node
struct node* create_node(int id, const char* name, int age, float gpa);

// Function to check if a student ID exists
int id_exists(int id);

// Function to add a student
void addStudent(const struct Student *const ptr);

// Function to display all students
void displayStudents(void);

// Function to search for a student by ID
void searchStudentByID(int id);

// Function to update student information
void updateStudent(int id);

// Function to calculate average GPA
float calculateAverageGPA(void);

// Function to find and display the student with the highest GPA
void searchHighestGPA(void);

// Function to delete a student by ID
void deleteStudent(int id);

// Function to print the menu
void printMenu(void);

// Function to handle menu options
void handleMenuOption(void);

#endif /* SLL_H_ */
