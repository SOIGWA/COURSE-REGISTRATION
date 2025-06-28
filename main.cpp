#include <iostream>
#include <string>
#include <limits>
#include "RegistrationSystem.h"

// Function prototypes
void displayMenu();
void handleStudentManagement(RegistrationSystem& system);
void handleCourseManagement(RegistrationSystem& system);
void handleRegistrationManagement(RegistrationSystem& system);
void clearInputBuffer();
int getIntInput();
std::string getStringInput();

int main() {
    RegistrationSystem system;
    
    // Add some sample data
    std::cout << "=== Initializing Course Registration System ===" << std::endl;
    
    // Add sample courses
    int course1 = system.addCourse("Computer Science 101", "Dr. Smith", 3, 30);
    int course2 = system.addCourse("Mathematics 201", "Prof. Johnson", 4, 25);
    int course3 = system.addCourse("Physics 101", "Dr. Brown", 3, 20);
    int course4 = system.addCourse("English Literature", "Prof. Davis", 3, 35);
    
    // Add sample students
    int student1 = system.addStudent("Alice Kosgei", "alicekosgei@email.com", "Computer Science");
    int student2 = system.addStudent("Andy Ombasa", "andyombasa@email.com", "Mathematics");
    int student3 = system.addStudent("Carol Wambugu", "carolwambugu@email.com", "Physics");
    
    // Sample registrations
    system.registerStudentForCourse(student1, course1);
    system.registerStudentForCourse(student1, course2);
    system.registerStudentForCourse(student2, course2);
    system.registerStudentForCourse(student2, course3);
    system.registerStudentForCourse(student3, course3);
    system.registerStudentForCourse(student3, course4);
    
    std::cout << "\nSample data initialized successfully!" << std::endl;
    
    int choice;
    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        choice = getIntInput();
        
        switch (choice) {
            case 1:
                handleStudentManagement(system);
                break;
            case 2:
                handleCourseManagement(system);
                break;
            case 3:
                handleRegistrationManagement(system);
                break;
            case 4:
                system.displaySystemStats();
                break;
            case 0:
                std::cout << "Thank you for using the Course Registration System!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
        }
        
        if (choice != 0) {
            std::cout << "\nPress Enter to continue...";
            std::cin.ignore();
            std::cin.get();
        }
        
    } while (choice != 0);
    
    return 0;
}

void displayMenu() {
    std::cout << "\n===============================================" << std::endl;
    std::cout << "      COURSE REGISTRATION SYSTEM" << std::endl;
    std::cout << "===============================================" << std::endl;
    std::cout << "1. Student Management" << std::endl;
    std::cout << "2. Course Management" << std::endl;
    std::cout << "3. Registration Management" << std::endl;
    std::cout << "4. View System Statistics" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "===============================================" << std::endl;
}

void handleStudentManagement(RegistrationSystem& system) {
    int choice;
    std::cout << "\n=== Student Management ===" << std::endl;
    std::cout << "1. Add New Student" << std::endl;
    std::cout << "2. Update Student Information" << std::endl;
    std::cout << "3. View All Students" << std::endl;
    std::cout << "4. View Student Schedule" << std::endl;
    std::cout << "Enter your choice: ";
    choice = getIntInput();
    
    switch (choice) {
        case 1: {
            std::cout << "Enter student name: ";
            std::string name = getStringInput();
            std::cout << "Enter student email: ";
            std::string email = getStringInput();
            std::cout << "Enter student major: ";
            std::string major = getStringInput();
            system.addStudent(name, email, major);
            break;
        }
        case 2: {
            std::cout << "Enter student ID: ";
            int studentId = getIntInput();
            std::cout << "Enter new name: ";
            std::string name = getStringInput();
            std::cout << "Enter new email: ";
            std::string email = getStringInput();
            std::cout << "Enter new major: ";
            std::string major = getStringInput();
            system.updateStudentInfo(studentId, name, email, major);
            break;
        }
        case 3:
            system.displayAllStudents();
            break;
        case 4: {
            std::cout << "Enter student ID: ";
            int studentId = getIntInput();
            system.displayStudentSchedule(studentId);
            break;
        }
        default:
            std::cout << "Invalid choice!" << std::endl;
    }
}

void handleCourseManagement(RegistrationSystem& system) {
    int choice;
    std::cout << "\n=== Course Management ===" << std::endl;
    std::cout << "1. Add New Course" << std::endl;
    std::cout << "2. Update Course Information" << std::endl;
    std::cout << "3. View All Courses" << std::endl;
    std::cout << "4. View Course Roster" << std::endl;
    std::cout << "Enter your choice: ";
    choice = getIntInput();
    
    switch (choice) {
        case 1: {
            std::cout << "Enter course name: ";
            std::string name = getStringInput();
            std::cout << "Enter instructor name: ";
            std::string instructor = getStringInput();
            std::cout << "Enter credits: ";
            int credits = getIntInput();
            std::cout << "Enter maximum capacity: ";
            int capacity = getIntInput();
            system.addCourse(name, instructor, credits, capacity);
            break;
        }
        case 2: {
            std::cout << "Enter course ID: ";
            int courseId = getIntInput();
            std::cout << "Enter new course name: ";
            std::string name = getStringInput();
            std::cout << "Enter new instructor name: ";
            std::string instructor = getStringInput();
            std::cout << "Enter new credits: ";
            int credits = getIntInput();
            std::cout << "Enter new maximum capacity: ";
            int capacity = getIntInput();
            system.updateCourseInfo(courseId, name, instructor, credits, capacity);
            break;
        }
        case 3:
            system.displayAllCourses();
            break;
        case 4: {
            std::cout << "Enter course ID: ";
            int courseId = getIntInput();
            system.displayCourseRoster(courseId);
            break;
        }
        default:
            std::cout << "Invalid choice!" << std::endl;
    }
}

void handleRegistrationManagement(RegistrationSystem& system) {
    int choice;
    std::cout << "\n=== Registration Management ===" << std::endl;
    std::cout << "1. Register Student for Course" << std::endl;
    std::cout << "2. Drop Student from Course" << std::endl;
    std::cout << "Enter your choice: ";
    choice = getIntInput();
    
    switch (choice) {
        case 1: {
            std::cout << "Enter student ID: ";
            int studentId = getIntInput();
            std::cout << "Enter course ID: ";
            int courseId = getIntInput();
            system.registerStudentForCourse(studentId, courseId);
            break;
        }
        case 2: {
            std::cout << "Enter student ID: ";
            int studentId = getIntInput();
            std::cout << "Enter course ID: ";
            int courseId = getIntInput();
            system.dropStudentFromCourse(studentId, courseId);
            break;
        }
        default:
            std::cout << "Invalid choice!" << std::endl;
    }
}

void clearInputBuffer() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int getIntInput() {
    int value;
    while (!(std::cin >> value)) {
        std::cout << "Invalid input! Please enter a number: ";
        clearInputBuffer();
    }
    clearInputBuffer();
    return value;
}

std::string getStringInput() {
    std::string input;
    if (std::cin.peek() == '\n') std::cin.ignore();
    std::getline(std::cin, input);
    return input;
}

