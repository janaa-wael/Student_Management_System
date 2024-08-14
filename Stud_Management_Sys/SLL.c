/*
 * SLL.c
 *
 *  Created on: Aug 14, 2024
 *      Author: hp
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "SLL.h"

struct Student{
	int id;
	char name[50];
	int age;
	float gpa;
};

struct node{
	struct Student data;
	struct node * next;
};

struct node* head = NULL;


struct node* create_node(int id, const char* name, int age, float gpa) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        return NULL;
    }
    new_node->data.id = id;
    strncpy(new_node->data.name, name, sizeof(new_node->data.name) - 1);
    new_node->data.name[sizeof(new_node->data.name) - 1] = '\0';
    new_node->data.age = age;
    new_node->data.gpa = gpa;
    new_node->next = NULL;
    return new_node;
}

// Function to check if a student ID exists
int id_exists(int id) {
    struct node* current = head;
    while (current != NULL) {
        if (current->data.id == id) {
            return 1; // ID exists
        }
        current = current->next;
    }
    return 0; // ID does not exist
}

// Function to add a student
void addStudent(const struct Student *const ptr) {
    if (id_exists(ptr->id)) {
        printf("Student with ID %d already exists.\n", ptr->id);
        return;
    }

    struct node* new_node = create_node(ptr->id, ptr->name, ptr->age, ptr->gpa);
    if (new_node == NULL) {
        return; // Memory allocation failed
    }

    if (head == NULL) {
        head = new_node;
    } else {
        struct node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }

    printf("Student added successfully.\n");
    return;
}

// Function to display all students
void displayStudents(void) {
    if (head == NULL) {
        printf("No students currently registered on the system.\n");
        return;
    }

    struct node* current = head;
    while (current != NULL) {
        printf("ID: %d, Name: %s, Age: %d, GPA: %.2f\n", current->data.id, current->data.name, current->data.age, current->data.gpa);
        current = current->next;
    }
}

// Function to search for a student by ID
void searchStudentByID(int id) {
    struct node* student = head;
    while (student != NULL) {
        if (student->data.id == id) {
            printf("Student found: ID: %d, Name: %s, Age: %d, GPA: %.2f\n", student->data.id, student->data.name, student->data.age, student->data.gpa);
            return;
        }
        student = student->next;
    }
    printf("Student with ID %d not found.\n", id);
}

void updateStudent(int id) {
    struct node* student = head;
    while (student != NULL) {
        if (student->data.id == id) {
            char name[50];
            int age;
            float gpa;

            printf("Enter new name: ");
            scanf(" %[^\n]s", name);
            printf("Enter new age: ");
            scanf(" %d", &age);
            printf("Enter new GPA: ");
            scanf(" %f", &gpa);

            // Update student details
            strncpy(student->data.name, name, sizeof(student->data.name) - 1);
            student->data.name[sizeof(student->data.name) - 1] = '\0';
            student->data.age = age;
            student->data.gpa = gpa;

            printf("Student information updated successfully.\n");
            return;
        }
        student = student->next;
    }
    printf("Student with ID %d not found.\n", id);
}

// Function to calculate average GPA
float calculateAverageGPA(void) {
    if (head == NULL) {
        return 0.0; // No students in the list
    }

    float total_gpa = 0.0;
    int count = 0;
    struct node* current = head;

    while (current != NULL) {
        total_gpa += current->data.gpa;
        count++;
        current = current->next;
    }

    return total_gpa / count;
}

// Function to find and display the student with the highest GPA
void searchHighestGPA(void) {
    if (head == NULL) {
        printf("No students are currently present.\n");
        return;
    }

    struct node* highest_gpa_student = head;
    struct node* current = head;

    while (current != NULL) {
        if (current->data.gpa > highest_gpa_student->data.gpa) {
            highest_gpa_student = current;
        }
        current = current->next;
    }

    printf("Student with highest GPA: ID: %d, Name: %s, Age: %d, GPA: %.2f\n", highest_gpa_student->data.id, highest_gpa_student->data.name, highest_gpa_student->data.age, highest_gpa_student->data.gpa);
}

// Function to delete a student by ID
void deleteStudent(int id) {
    struct node* current = head;
    struct node* previous = NULL;

    // Check if the list is empty
    if (current == NULL) {
        printf("No students are currently present.\n");
        return;
    }

    // Search for the student with the given ID
    while (current != NULL && current->data.id != id) {
        previous = current;
        current = current->next;
    }

    // If the student was not found
    if (current == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    // If the student to be deleted is the head node
    if (previous == NULL) {
        head = current->next; // Move head to the next node
    } else {
        previous->next = current->next; // Bypass the current node
    }

    // Free the memory allocated for the node
    free(current);

    printf("Student with ID %d deleted successfully.\n", id);
}

void printMenu(void) {
    printf("\n--- Student Management System ---\n");
    printf("1. Add a Student\n");
    printf("2. Display All Students\n");
    printf("3. Search for a Student by ID\n");
    printf("4. Update Student Information\n");
    printf("5. Delete a Student\n");
    printf("6. Calculate Average GPA\n");
    printf("7. Find Student with Highest GPA\n");
    printf("8. Exit\n");
    printf("--------------------------------\n");
}

// Function to handle menu options
void handleMenuOption() {
	int id, choice;
	struct Student student;
	struct Student* ptr_Student = &student;
	printf("Enter your choice : ");
	scanf("%d",&choice);
	struct node* new_node;

	    switch (choice) {
	        case 1:
	            // Add a Student
	            printf("Enter student ID: ");
	            scanf(" %d", &student.id);
	            printf("Enter student name: ");
	            scanf(" %[^\n]s", student.name);
	            printf("Enter student age: ");
	            scanf(" %d", &student.age);
	            printf("Enter student GPA: ");
	            scanf(" %f", &student.gpa);

	            // Use create_node to create a new node
	            new_node = create_node(student.id, student.name, student.age, student.gpa);
	            if (new_node == NULL) {
	                printf("Failed to add student.\n");
	                return;
	            }

	            // Add the node to the end of the list
	            if (head == NULL) {
	                head = new_node;
	            }
	            addStudent(ptr_Student);
	            break;

	        case 2:
	            // Display All Students
	            displayStudents();
	            break;

	        case 3:
	            // Search for a Student by ID
	            printf("Enter student ID to search: ");
	            scanf("%d", &id);
	            searchStudentByID(id);
	            break;

	        case 4:
	            // Update Student Information
	            printf("Enter student ID to update: ");
	            scanf("%d", &id);
	            updateStudent(id);
	            break;

	        case 5:
	            // Delete a Student
	            printf("Enter student ID to delete: ");
	            scanf("%d", &id);
	            deleteStudent(id);
	            break;

	        case 6:
	            // Calculate Average GPA
	            printf("Average GPA: %.2f\n", calculateAverageGPA());
	            break;

	        case 7:
	            // Find Student with Highest GPA
	            searchHighestGPA();
	            break;

	        default:
	            printf("Invalid choice, please try again.\n");
	            break;
	    }


}
