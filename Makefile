CC = gcc
CFLAGS = -Wall -Wextra -std=c11
SRC = src/main.c src/employee.c src/file_operations.c
OBJ = main.o employee.o file_operations.o
INC = -Iinclude
OUT = employee_management.exe

all: $(OUT)

$(OUT): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(OUT)

main.o: src/main.c include/employee.h include/file_operations.h
	$(CC) $(CFLAGS) $(INC) -c src/main.c -o main.o

employee.o: src/employee.c include/employee.h
	$(CC) $(CFLAGS) $(INC) -c src/employee.c -o employee.o

file_operations.o: src/file_operations.c include/file_operations.h
	$(CC) $(CFLAGS) $(INC) -c src/file_operations.c -o file_operations.o

clean:
	del /Q $(OBJ) $(OUT)

