#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file_operations.h"

// Function to create and add a new record
void create(const char *filename) {
    employee e;
    FILE *file = fopen(filename, "ab");
    if (file == NULL) {
        printf("\nERROR: Unable to open file for writing!\n");
        return;
    }

    printf("Enter the Employee ID: ");
    scanf("%d", &e.employeeId);
    if (isEmployeeIdExists(filename, e.employeeId)) {
        printf("Employee already exists!\n");
        fclose(file);
        return;
    }

    while (getchar() != '\n');
    printf("Enter the Employee Name: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = '\0';

    printf("Enter the Age: ");
    scanf("%d", &e.age);
    while (getchar() != '\n');

    printf("Enter the Designation: ");
    fgets(e.designation, sizeof(e.designation), stdin);
    e.designation[strcspn(e.designation, "\n")] = '\0';

    printf("Enter the Experience (in years): ");
    scanf("%d", &e.experience);
    while (getchar() != '\n');

    printf("Enter the Joining Date (DD/MM/YYYY): ");
    fgets(e.joiningDate, sizeof(e.joiningDate), stdin);
    e.joiningDate[strcspn(e.joiningDate, "\n")] = '\0';

    fwrite(&e, sizeof(employee), 1, file);
    printf("Record successfully added\n");
    fclose(file);
}

// Function to delete a record
void deleteRecord(const char *filename, int empID) {
    employee e;
    int found = 0;
    FILE *file = fopen(filename, "rb");
    FILE *temp = fopen("temp.dat", "wb");

    if (file == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }

    while (fread(&e, sizeof(employee), 1, file)) {
        if (empID == e.employeeId) {
            found = 1;
            printf("Record %d successfully deleted\n", empID);
        } else {
            fwrite(&e, sizeof(employee), 1, temp);
        }
    }

    fclose(file);
    fclose(temp);
    remove(filename);
    rename("temp.dat", filename);

    if (!found) {
        printf("Employee with ID %d not found.\n", empID);
    }
}

// Function to sort records by age
void sortbyage(const char *filename, const char *sortedfile) {
    employee e;
    int count = 0;
    FILE *file = fopen(filename, "rb");

    if (file == NULL) {
        printf("\nERROR: File not opened");
        return;
    }

    while (fread(&e, sizeof(employee), 1, file)) {
        count++;
    }
    if (count == 0) {
        printf("\nNo records to sort!\n");
        fclose(file);
        return;
    }

    employee *arr = malloc(count * sizeof(employee));
    rewind(file);

    for (int i = 0; i < count; i++) {
        fread(&arr[i], sizeof(employee), 1, file);
    }
    fclose(file);

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (arr[j].age > arr[j + 1].age) {
                employee tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
        }
    }

    FILE *sortedfp = fopen(sortedfile, "wb");
    fwrite(arr, sizeof(employee), count, sortedfp);
    fclose(sortedfp);
    free(arr);
    printf("\nRecords sorted by age successfully!\n");
}