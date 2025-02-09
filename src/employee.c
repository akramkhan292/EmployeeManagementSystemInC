#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "employee.h"

// Function to display an employee object
void displayobj(employee e) {
    printf("\t ________________________________________\n");
    printf("\t| EmployeeID:   |  %-21d |\n", e.employeeId);
    printf("\t| Name:         |  %-21s |\n", e.name);
    printf("\t| Age:          |  %-21d |\n", e.age);
    printf("\t| Designation:  |  %-21s |\n", e.designation);
    printf("\t| Experience:   |  %-21d |\n", e.experience);
    printf("\t| Joining Date: |  %-21s |\n", e.joiningDate);
    printf("\t------------------------------------------");
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
    printf("\n\n \t\tEmployees\n\n");
    while (fread(&e, sizeof(employee), 1, file)) {
        printf("Record %d:\n", ++i);
        displayobj(e);
        printf("\n");
    }
    fclose(file);
}

// Buffer after output.
void buffer(char ch){
    while (1)
            {
                printf("\nEnter Y to continue to main menu.\n");
                scanf(" %c",&ch);
                if (ch == 'y' || ch == 'Y') 
                {
                    break;
                }
                else{
                    printf("\nInvalid Input!");
                }
            }
}
