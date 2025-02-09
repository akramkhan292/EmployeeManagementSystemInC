# Employee Management System

## Overview
The **Employee Management System** is a C-based program for managing employee records. It allows users to **add, delete, search, sort, and display** employee data using a menu-driven interface.

## Features
- 📌 **Add** new employee records.  
- 🗑 **Delete** an employee record by ID.  
- 🔍 **Search** for an employee record by ID.  
- 📊 **Sort** employee records by age.  
- 📃 **Display** all employee records.  

## Usage
### 🔧 Compilation  
Use the provided `Makefile` to compile the program:  
```bash
make
```

### ▶️ Running the Program  
Execute the compiled binary:  
```bash
./employee_management
```

### 🏗 Menu Options  
Once running, follow the interactive menu to perform actions like adding, deleting, searching, and sorting employee records.

---

## 📂 Project Structure
```
├── data/                       # Directory for employee data storage
│   ├── record.dat              # Binary file to store employee records
│   ├── sortedbyage.dat         # Binary file for sorted records
│
├── include/                    # Header files directory
│   ├── employee.h              # Employee structure & function declarations
│   ├── file_operations.h       # File operation declarations
│   ├── utils.h                 # Utility function declarations
│
├── src/                        # Source code directory
│   ├── employee.c              # Employee management functions
│   ├── file_operations.c       # File handling functions
│   ├── utils.c                 # Utility functions
│   ├── main.c                  # Entry point of the program
│   ├── tempCodeRunnerFile.c    # Temporary file (optional, may be ignored)
│
├── Makefile                    # Build automation script
├── README.md                   # Project documentation
```

---

## 📁 Data Storage
- Employee records are saved in a **binary file** named `record.dat` inside the `data/` folder.  
- When sorted by age, records are saved in `sortedbyage.dat` in the same folder.

---

## ⚠️ Notes
- This implementation is **basic** and lacks robust **input validation** or advanced **error handling**.  
- Potential enhancements:
  - Add **input validation** for better data integrity.
  - Implement advanced error handling for edge cases.
  - Use **database integration** for scalability.