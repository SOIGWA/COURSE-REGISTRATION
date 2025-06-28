# COURSE-REGISTRATION
course registration systems using python and using c++
# Course Registration System - Python

A simple and easy-to-use Course Registration System implemented in Python using Object-Oriented Programming principles.

## Features

- **Student Management**: Add students and view their information
- **Course Management**: Add courses with capacity limits
- **Registration**: Register students for courses with automatic validation
- **Easy Interface**: Simple menu-driven console application

## Files

- `student.py` - Student class definition
- `course.py` - Course class definition  
- `registration_system.py` - Main system logic
- `main.py` - User interface and program entry point

## How to Run

1. Make sure you have Python installed (Python 3.6 or higher)
2. Navigate to the `COURSE REGISTRATION` directory
3. Run the program:
```bash,command prompt
python main.py
```

## Usage

The program will start with sample data (2 students and 2 courses) and present a menu with these options:

1. **Add Student** - Create a new student record
2. **Add Course** - Create a new course
3. **Register Student for Course** - Enroll a student in a course
4. **Drop Student from Course** - Remove a student from a course
5. **View All Students** - List all registered students
6. **View All Courses** - List all available courses
7. **View Student Details** - Show detailed student information
8. **View Course Details** - Show detailed course information
9. **Exit** - Close the program

## Example Usage

```
COURSE REGISTRATION SYSTEM
========================================
1. Add Student
2. Add Course
3. Register Student for Course
...

Enter your choice (1-9): 3
Enter student ID: 1001
Enter course ID: 101
Alice Kosgei successfully registered for Python Programming
```

## Key Features

- **Simple Design**: Easy to understand and modify
- **Error Handling**: Prevents duplicate enrollments and handles capacity limits
- **Interactive Menu**: User-friendly console interface
- **Sample Data**: Comes with pre-loaded examples to test immediately

## Code Structure

- **Student Class**: Manages student information and enrolled courses
- **Course Class**: Manages course details and enrolled students  
- **RegistrationSystem Class**: Handles all operations and data management
- **Main Function**: Provides the user interface

This system demonstrates basic OOP concepts in Python while solving a practical problem!

