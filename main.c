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
void create()
{
    employee e;
    printf("Enter the employeeID: ");
    scanf("%d", &e.employeeId);
    printf("Enter the Employee Name: ");
    scanf("%s", &e.name);
    printf("Enter the age: ");
    scanf("%d", &e.age);
    printf("Enter the Designation: ");
    scanf("%s", &e.designation);
    printf("Enter the experience: ");
    scanf("%d", &e.experience);
    printf("Enter the Joining Date: ");
    scanf("%s", &e.joiningDate);
}
int main()
{
    int c;
    do
    {
        printf("Welcome to Employee Managment System");
        printf("\nSelect the below option");
        printf("\n1.Add a new Entry");
        printf("\n2.Delete entries");
        printf("\n3.Search a Record");
        printf("\n4.Sort by age");
        printf("\n5.Display Record");
        printf("\n6.Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            create();
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