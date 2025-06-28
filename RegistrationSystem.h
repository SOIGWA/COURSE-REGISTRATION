
#ifndef REGISTRATION_SYSTEM_H
#define REGISTRATION_SYSTEM_H

#include <vector>
#include <memory>
#include <map>
#include "Student.h"
#include "Course.h"

class RegistrationSystem {
private:
    std::vector<std::unique_ptr<Student>> students;
    std::vector<std::unique_ptr<Course>> courses;
    int nextStudentId;
    int nextCourseId;
    
public:
    // Constructor
    RegistrationSystem();
    
    // Student management
    int addStudent(const std::string& name, const std::string& email, const std::string& major);
    Student* findStudent(int studentId);
    bool updateStudentInfo(int studentId, const std::string& name, 
                          const std::string& email, const std::string& major);
    void displayAllStudents() const;
    
    // Course management
    int addCourse(const std::string& name, const std::string& instructor, 
                  int credits, int maxCapacity);
    Course* findCourse(int courseId);
    bool updateCourseInfo(int courseId, const std::string& name, 
                         const std::string& instructor, int credits, int maxCapacity);
    void displayAllCourses() const;
    
    // Registration management
    bool registerStudentForCourse(int studentId, int courseId);
    bool dropStudentFromCourse(int studentId, int courseId);
    void displayStudentSchedule(int studentId) const;
    void displayCourseRoster(int courseId) const;
    
    // System statistics
    void displaySystemStats() const;
    
    // Destructor
    ~RegistrationSystem();
};

#endif // REGISTRATION_SYSTEM_H
