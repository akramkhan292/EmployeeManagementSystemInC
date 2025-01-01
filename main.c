#include <stdio.h>
typedef struct employee
{
    int employeeId;
    char name[50];
    int age;
    char designation[50];
    int experience;
    char joiningDate[11];
} employee;
void create(FILE *fp)
{
    employee e;
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
    if(fp == NULL){
        printf("\nERROR file not opened");
    }
    else{
        fprintf(fp,"employeeID: %d, Employee Name: %s, age: %d, Designation: %s, experience: %d, Joining Date: %s\n", e.employeeId,e.name,e.age,e.designation,e.experience,e.joiningDate);
    }
}
int main()
{
    FILE *fp;
    int c;
    fp = fopen("record.txt","a+");
    printf("\n\n\n\n---------------- WELCOME TO EMPLOYEE MANAGEMENT SYSTEM ----------------\n\n");
    do
    {
        printf("\nSelect the below option\n");
        printf("\n\t1. Add a new Entry");
        printf("\n\t2. Delete entries");
        printf("\n\t3. Search a Record");
        printf("\n\t4. Sort by age");
        printf("\n\t5. Display Record");
        printf("\n\t6. Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            create(fp);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        default:
            printf("Invalid!");
            break;
        }
    } while (c != 6);
    return 0;
}