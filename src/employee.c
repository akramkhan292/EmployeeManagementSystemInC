#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "employee.h"

// Function to display an employee object
void displayobj(employee e) {
    printf("\tEmployeeID: %d\n", e.employeeId);
    printf("\tName: %s\n", e.name);
    printf("\tAge: %d\n", e.age);
    printf("\tDesignation: %s\n", e.designation);
    printf("\tExperience: %d\n", e.experience);
    printf("\tJoining Date: %s\n", e.joiningDate);
}

// Function to check if Employee ID exists
int isEmployeeIdExists(const char *filename, int id) {
    employee e;
    FILE *file = fopen(filename, "rb"); 
    if (file == NULL) return 0;

    while (fread(&e, sizeof(employee), 1, file)) {
        if (e.employeeId == id) {
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

// Function to search a record by Employee ID
void searchbyEmpID(const char *filename, int empID) {
    employee e;
    int found = 0;
    FILE *file = fopen(filename, "rb");
    if (file == NULL) {
        printf("\nERROR: File not opened");
        return;
    }

    while (fread(&e, sizeof(employee), 1, file)) {
        if (empID == e.employeeId) {
            found = 1;
            displayobj(e);
        }
    }

    if (found) {
        printf("\nSearch Completed!\n");
    } else {
        printf("\nNo Record Found!\n");
    }
    fclose(file);
}

// Function to display all records
void display(const char *filename) {
    employee e;
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("\nERROR: File not opened");
        return;
    }

    int i = 0;
    while (fread(&e, sizeof(employee), 1, file)) {
        printf("Record %d:\n", ++i);
        displayobj(e);
        printf("\n");
    }
    fclose(file);
}
