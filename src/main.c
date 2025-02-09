#include <stdio.h>
#include<string.h>
#include "employee.h"
#include "file_operations.h"
int main()
{

    const char *filename = "./data/record.dat";            //file to store employee record
    const char *sortedfile = "./data/sortedbyage.dat";     //file to store storted record by age
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
            deleteRecord(filename, empID);
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
        case 5:
            // display records from the chossen file
            display(filename);
            break;
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