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
        fwrite(&e,sizeof(employee),1,fp);
        printf("Record Succesfully added\n");
    }
}
void delete(const char *filename, int empID){
    employee e;
    int found = 0;
    FILE *file = fopen(filename,"rb");
    FILE *temp = fopen("temp.dat","wb");
    if (file == NULL || temp == NULL) {
        printf("Error opening file!\n");
        return;
    }
    while (fread(&e, sizeof(employee),1, file))
    {
        if(empID==e.employeeId){
            found = 1;
            printf("record %d successfully deleted", empID);
        }
        else{
            fwrite(&e,sizeof(employee),1,temp);
        }
    }
    fclose(file);
    fclose(temp);
    remove(filename);
    rename("temp.dat",filename);
    if (!found) {
        printf("Employee with ID %d not found.\n", empID);
    }
    

}
int main()
{
    const char *filename  = "record.dat";
    FILE *fp;
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
        printf("\n\t6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
        fp = fopen(filename,"ab");
        if (fp == NULL) {
                    printf("Error opening file!\n");
                } else {
                    create(fp);
                    fclose(fp);
                }
            break;
        case 2: {
            int empID;
            printf("enter employeeID to be deleted: ");
            scanf("%d",&empID);
            delete(filename,empID);
            break;
        }
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
    } while (choice != 6);
    //fclose(fp);
    return 0;
}