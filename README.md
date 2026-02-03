# Student Management System (C)

## Project Overview
A simple and efficient **Student Management System** implemented in **C** using a **singly linked list**.
The project allows users to manage student records dynamically through a console-based menu system.

Each student record includes:
- Student ID
- Name
- Age
- GPA

Author: Asser Hossam El-Hosary  
Created: August 10, 2024  
Project Type: Educational / Embedded C Practice

---

## Tech Stack
- **Language:** C (ANSI C)
- **Compiler:** GCC (MinGW)
- **IDE:** Eclipse CDT
- **Data Structure:** Singly Linked List
- **Memory Management:** malloc() / free()
- **Platform:** Windows (Console)

---

## Architecture
The project follows a procedural architecture:
- `student` structure for student data
- `node` structure for linked list nodes
- Global head pointer to manage the list
- Modular functions for each operation

---

## Features
- Add new student (with duplicate ID check)
- Display all students
- Search student by ID
- Update student information
- Delete student by ID
- Calculate average GPA
- Find student with highest GPA
- Dynamic memory handling
- Menu-driven console interface

---

## Testing
The system was tested manually for:
- Empty list handling
- Duplicate ID prevention
- Update and delete operations
- GPA calculations
- Invalid ID searches

---

## Folder Structure
```
c_project/
│
├── main.c
├── .settings/
│   └── language.settings.xml
├── Debug/
├── Release/
└── README.md
```

---

## How to Run the Project

### Using GCC
```bash
gcc main.c -o student_management
./student_management
```

### Using Eclipse CDT
1. Import project as Existing C Project
2. Build the project
3. Run as Local C Application

---

## Future Improvements
- File handling (save/load)
- Safer input handling (replace gets)
- Sorting students
- GUI version
- Code modularization
- Database integration

---

## Screenshots
Add screenshots of:
- Main menu
- Add student
- Display students

---

## Social Links
- LinkedIn: https://www.linkedin.com/in/asser-elhosary
- GitHub: https://github.com/asser-elhosary

---

## License
Open-source project for learning and educational purposes.
