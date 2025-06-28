
#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <vector>
#include <iostream>

class Course; // Forward declaration

class Student {
private:
    int studentId;
    std::string name;
    std::string email;
    std::string major;
    std::vector<Course*> enrolledCourses;
    
public:
    // Constructors
    Student();
    Student(int id, const std::string& name, const std::string& email, const std::string& major);
    
    // Getters
    int getStudentId() const;
    std::string getName() const;
    std::string getEmail() const;
    std::string getMajor() const;
    std::vector<Course*> getEnrolledCourses() const;
    
    // Setters
    void setName(const std::string& name);
    void setEmail(const std::string& email);
    void setMajor(const std::string& major);
    
    // Course management
    bool enrollInCourse(Course* course);
    bool dropCourse(int courseId);
    void displayEnrolledCourses() const;
    bool isEnrolledInCourse(int courseId) const;
    
    // Display student information
    void displayStudentInfo() const;
    
    // Destructor
    ~Student();
};

#endif // STUDENT_H
