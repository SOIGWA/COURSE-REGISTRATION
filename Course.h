
#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>
#include <iostream>

class Student; // Forward declaration

class Course {
private:
    int courseId;
    std::string courseName;
    std::string instructor;
    int credits;
    int maxCapacity;
    std::vector<Student*> enrolledStudents;
    
public:
    // Constructors
    Course();
    Course(int id, const std::string& name, const std::string& instructor, 
           int credits, int maxCapacity);
    
    // Getters
    int getCourseId() const;
    std::string getCourseName() const;
    std::string getInstructor() const;
    int getCredits() const;
    int getMaxCapacity() const;
    int getCurrentEnrollment() const;
    std::vector<Student*> getEnrolledStudents() const;
    
    // Setters
    void setCourseName(const std::string& name);
    void setInstructor(const std::string& instructor);
    void setCredits(int credits);
    void setMaxCapacity(int capacity);
    
    // Student management
    bool addStudent(Student* student);
    bool removeStudent(int studentId);
    bool isStudentEnrolled(int studentId) const;
    bool isFull() const;
    
    // Display course information
    void displayCourseInfo() const;
    void displayEnrolledStudents() const;
    
    // Destructor
    ~Course();
};

#endif // COURSE_H
