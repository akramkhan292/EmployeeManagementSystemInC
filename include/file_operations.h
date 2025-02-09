#ifndef FILE_OPERATIONS_H
#define FILE_OPERATIONS_H

#include "employee.h"

void create(const char *filename);
void deleteRecord(const char *filename, int empID);
void sortbyage(const char *filename, const char *sortedfile);


#endif