#include <stdio.h>
#include<string.h>
#include <stdlib.h>

// employee structure for creating employee object
typedef struct employee
{
    int employeeId;             // Unique ID of the employee
    char name[50];              // Name of the employee
    int age;                    // Age of the employee
    char designation[50];       // Designation of the employee
    int experience;             // Experience of the employee
    char joiningDate[11];       // Joining Date of the employee
} employee;


// Function to display an employee object
void displayobj(employee e)
{
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
    FILE *file = fopen(filename,"rb"); 

    
    // fseek(file, 0, SEEK_END);
    // long fileSize = ftell(file);
    // rewind(file);

    // if (fileSize == 0) {
    //     printf("DEBUG: File is empty, no employees exist.\n");
    //     return 0; // No data in file
    // } else {
    //     printf("DEBUG: File size = %ld bytes, reading data...\n", fileSize);
    // }

    // printf("\nChecking if Employee ID %d exists...\n", id);
    
    while (fread(&e, sizeof(employee), 1, file)) {
        //  printf("DEBUG: Read Employee ID %d from file\n", e.employeeId);
        if (e.employeeId == id) {
            fclose(file);
            // printf("DEBUG: Match Found! Employee ID %d already exists.\n", id);
            return 1; // Employee ID found
        }
    }
    fclose(file);
    // printf("DEBUG: No match found. Employee ID %d is unique.\n", id);
    return 0; // Employee ID not found
}

// function to create and add a new record
void create(const char *filename) {
    employee e;
    FILE *file = fopen(filename,"ab");
    if (file == NULL) {
        printf("\nERROR: Unable to open file for writing!\n");
        return;
    }
    // Taking input from the user for the employee record
    printf("Enter the Employee ID: ");
    scanf("%d", &e.employeeId);

    // Check if Employee ID already exists
    if (isEmployeeIdExists(filename, e.employeeId)) {
        printf("Employee already exists!\n");
        return;
    }

    // Clear input buffer
    while (getchar() != '\n');

    printf("Enter the Employee Name: ");
    fgets(e.name, sizeof(e.name), stdin);
    e.name[strcspn(e.name, "\n")] = '\0'; // Remove newline character

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

    // Check if file pointer is valid
    if (file == NULL) {
        printf("\nERROR: File not opened\n");
    } else {
        // Writing employee record in the file
        fwrite(&e, sizeof(employee), 1, file);
        printf("Record successfully added\n");
    }
    fclose(file);
}


// Function to delete a record in a file
void delete(const char *filename, int empID)
{
    employee e;
    int found = 0;
    FILE *file = fopen(filename, "rb");
    FILE *temp = fopen("temp.dat", "wb"); // opening new temporary file

    // Check if both file pointers are valid
    if (file == NULL || temp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }

    // Reading records from a file and copying those that are not to be deleted
    while (fread(&e, sizeof(employee), 1, file))
    {
        if (empID == e.employeeId)
        {
            found = 1; // skippping this record for deletion purpose
            printf("record %d successfully deleted", empID);
        }
        else
        {
            fwrite(&e, sizeof(employee), 1, temp); // writing record which is not to be deleted
        }
    }

    fclose(file);
    fclose(temp);

    // replace the original file with the updated one
    remove(filename);             
    rename("temp.dat", filename); 

    if (!found)
    {
        printf("Employee with ID %d not found.\n", empID); // record isn't there to be deleted
    }
}


// function to serach a record by employeeID
void searchbyEmpID(const char *filename, int empID)
{
    employee e;
    int found = 0;
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("\nERROR File not opened");
        return;
    }
    // reading records from the file
    while (fread(&e, sizeof(employee), 1, file))
    {
        // print the record which is to be searched
        if (empID == e.employeeId)
        {
            found = 1;
            printf("\n\nemployeeID: %d\nName: %s\nAge: %d\nDesignation: %s\nExperience: %d\nJoining Date: %s\n", e.employeeId, e.name, e.age, e.designation, e.experience, e.joiningDate);
        }
    }
    if (found == 1)
    {
        printf("\n\nSearch Completed!\n\n");
    }
    else
    {
        printf("\n\nNo Record Found!\n\n");
    }
    fclose(file);
}


// function to create a file of sorted record by age
void sortbyage(const char *filename, const char *sortedfile)
{
    employee e;
    int count = 0;

    //open the input and output files
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("\nERROR File not opened");
        return;
    }

    //count the numbers of records
    while (fread(&e, sizeof(employee), 1, file))
    {
        count++;
    }
    if (count == 0)
    {
        printf("\nNo records to sort!\n");
        fclose(file);
        return;
    }
    //allocate memory for the array of employee
    employee *arr = malloc(count * sizeof(employee));
    rewind(file);

    //read records into the array
    int i = 0;
    while (fread(&e, sizeof(employee), 1, file))
    {
        arr[i] = e;
        i++;
    }
    fclose(file);

    //soting array by age using bubble sort
    for (int i = 0; i < count-1; i++)
    {
        for (int j = 0; j < count-i-1; j++)
        {
            if (arr[i].age < arr[j+1].age)
            {
                employee tmp;
                tmp = arr[i];
                arr[i] = arr[j+1];
                arr[j+1] = tmp;
            }
        }
    }
    FILE *sortedfp = fopen(sortedfile, "wb");
    if (sortedfp == NULL)
    {
        printf("\nERROR: Unable to open sorted file!\n");
        free(arr);
        return;
    }
    // writing the array of records into output file
    fwrite(arr, sizeof(employee), count, sortedfp);
    printf("\nRecords sorted by age successfully!\n");
    fclose(sortedfp);
    free(arr);
}
// function to dispaly record in a file
void display(const char *filename)
{
    employee e;
    // opening input file in reading mode
    FILE *file = fopen(filename, "rb");

    //check if file pointer is valid
    if (file == NULL)
    {
        printf("\nERROR File not opened");
        return;
    }
    //reading employee record from the file
    int i = 0;
    while (fread(&e, sizeof(employee), 1, file))
    {
        i++;
        printf("Record %d:\n", i);
        //calling display function of an employee object
        displayobj(e);
        printf("\n");
    }
    fclose(file);
}
int main()
{

    const char *filename = "record.dat";            //file to store employee record
    const char *sortedfile = "sortedbyage.dat";     //file to store storted record by age
    int flag = 0;
    int choice;
    printf("\n\n\n\n---------------- WELCOME TO EMPLOYEE MANAGEMENT SYSTEM ----------------\n\n");
    do
    {
        // menu for the employee management
        printf("\nSelect the below option\n");
        printf("\n\t1. Add a new Entry");
        printf("\n\t2. Delete entries");
        printf("\n\t3. Search a Record");
        printf("\n\t4. Sort by age");
        printf("\n\t5. Display Record");
        printf("\n\t6. exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            //add a new entry
            create(filename);
            break;
        case 2:
        {
            // delete a record
            int empID;
            printf("\n\nEnter employeeID to be deleted: ");
            scanf("%d", &empID);
            delete (filename, empID);
            break;
        }
        case 3:
        {
            // search a record
            int empID;
            printf("\n\nEnter employeeID to Search: ");
            scanf("%d", &empID);
            searchbyEmpID(filename, empID);
            break;
        }
        case 4:
            // sort the employee record by age
            sortbyage(filename, sortedfile);
            // displaying the sorted record
            display(sortedfile);
            break;
        case 5:{
            // display records from the chossen file
            int option;
            do
            {
                printf("1. %s\n", filename);
                printf("2. %s\n", sortedfile);
                printf("3. Exit\n");
                printf("\tOption: ");
                scanf("%d", &option);
                printf("\n\n");
                if (option == 1)
                {
                    display(filename);
                }
                else if (option == 2)
                {
                    display(sortedfile);
                }
                else if (option == 3)
                {
                    printf("Exit\n");
                }

                else
                {
                    printf("Invalid Option\n");
                }
            } while (option != 3);
            break;
        }
        case 6:
            // exit the code or menu
            printf("exit\n");
            break;
        default:
            // invalid option for error handling
            printf("Invalid!");
            break;
        }
        flag++;
        if (flag == 10000)
        {
            printf("\nERROR!\n");       // safety condition to prevent infinite loops
            break;
        }
    } while (choice != 6);
    return 0;
}