#include <stdio.h>
#include <stdlib.h>
// employee structure for creating employee object
typedef struct employee
{
    int employeeId;
    char name[50];
    int age;
    char designation[50];
    int experience;
    char joiningDate[11];
} employee;

// Display function of object employee
void displayobj(employee e)
{
    printf("\tEmployeeID: %d\n", e.employeeId);
    printf("\tName: %s\n", e.name);
    printf("\tAge: %d\n", e.age);
    printf("\tDesignation: %s\n", e.designation);
    printf("\tExperience: %d\n", e.experience);
    printf("\tJoining Date: %s\n", e.joiningDate);
}

// function to create and add a new record
void create(FILE *fp)
{
    employee e;
    // taking input from the user of employee record
    printf("Enter the employeeID: ");
    scanf("%d", &e.employeeId);
    printf("Enter the Employee Name: ");
    scanf("%s", e.name);
    printf("Enter the age: ");
    scanf("%d", &e.age);
    printf("Enter the Designation: ");
    scanf("%s", e.designation);
    printf("Enter the experience: ");
    scanf("%d", &e.experience);
    printf("Enter the Joining Date: ");
    scanf("%s", e.joiningDate);
    if (fp == NULL)
    {
        printf("\nERROR file not opened");
    }
    else
    {
        // writing employee record in the file
        fwrite(&e, sizeof(employee), 1, fp);
        printf("Record Succesfully added\n");
    }
}
// function to delete a record in a file
void delete(const char *filename, int empID)
{
    employee e;
    int found = 0;
    FILE *file = fopen(filename, "rb");
    FILE *temp = fopen("temp.dat", "wb"); // opening new temporary file
    if (file == NULL || temp == NULL)
    {
        printf("Error opening file!\n");
        return;
    }
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
    remove(filename);             // deleting existing file
    rename("temp.dat", filename); // renaming the new written file to the existing filename
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
    while (fread(&e, sizeof(employee), 1, file))
    {
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
    FILE *file = fopen(filename, "rb");
    FILE *sortedfp = fopen(sortedfile, "wb");
    if (file == NULL)
    {
        printf("\nERROR File not opened");
        return;
    }
    while (fread(&e, sizeof(employee), 1, file))
    {
        count++;
    }
    employee *arr = malloc(count * sizeof(employee));
    rewind(file);
    int i = 0;
    while (fread(&e, sizeof(employee), 1, file))
    {
        arr[i] = e;
        i++;
    }
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            if (arr[i].age < arr[j].age)
            {
                employee tmp;
                tmp = arr[i];
                arr[i] = arr[j];
                arr[j] = tmp;
            }
        }
    }
    for (int i = 0; i < count; i++)
    {
        fwrite(&arr[i], sizeof(employee), 1, sortedfp);
    }
    fclose(file);
    fclose(sortedfp);
}
// function to dispaly record in a file
void display(const char *filename)
{
    employee e;
    FILE *file = fopen(filename, "rb");
    if (file == NULL)
    {
        printf("\nERROR File not opened");
        return;
    }
    int i = 0;
    while (fread(&e, sizeof(employee), 1, file))
    {
        i++;
        printf("Record %d:\n", i);
        displayobj(e);
        printf("\n");
    }
    fclose(file);
}
int main()
{
    const char *filename = "record.dat";
    const char *sortedfile = "sortedbyage.dat";
    FILE *fp;
    int flag = 0;
    int choice;
    printf("\n\n\n\n---------------- WELCOME TO EMPLOYEE MANAGEMENT SYSTEM ----------------\n\n");
    do
    {
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
            fp = fopen(filename, "ab");
            if (fp == NULL)
            {
                printf("Error opening file!\n");
            }
            else
            {
                create(fp);
                fclose(fp);
            }
            break;
        case 2:
        {
            int empID;
            printf("\n\nEnter employeeID to be deleted: ");
            scanf("%d", &empID);
            delete (filename, empID);
            break;
        }
        case 3:
        {
            int empID;
            printf("\n\nEnter employeeID to Search: ");
            scanf("%d", &empID);
            searchbyEmpID(filename, empID);
            break;
        }
        case 4:
            sortbyage(filename, sortedfile);
            display(sortedfile);
            break;
        case 5:{
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
            printf("exit\n");
            break;
        default:
            printf("Invalid!");
            break;
        }
        flag++;
        if (flag == 10000)
        {
            printf("\nERROR!\n");
            break;
        }
    } while (choice != 6);
    return 0;
}