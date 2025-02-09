#ifndef EMPLOYEE_H
#define EMPLOYEE_H

typedef struct employee {
    int employeeId;
    char name[50];
    int age;
    char designation[50];
    int experience;
    char joiningDate[11];
} employee;

void displayobj(employee e);
int isEmployeeIdExists(const char *filename, int id);
void searchbyEmpID(const char *filename, int empID);
void display(const char *filename);

#endif
