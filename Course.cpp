#include "Course.h"
#include "Student.h"
#include <algorithm>
#include <iomanip>

// Constructors
Course::Course() : courseId(0), courseName(""), instructor(""), credits(0), maxCapacity(0) {}

Course::Course(int id, const std::string& name, const std::string& instructor, 
               int credits, int maxCapacity)
    : courseId(id), courseName(name), instructor(instructor), 
      credits(credits), maxCapacity(maxCapacity) {}

// Getters
int Course::getCourseId() const {
    return courseId;
}

std::string Course::getCourseName() const {
    return courseName;
}

std::string Course::getInstructor() const {
    return instructor;
}

int Course::getCredits() const {
    return credits;
}

int Course::getMaxCapacity() const {
    return maxCapacity;
}

int Course::getCurrentEnrollment() const {
    return enrolledStudents.size();
}

std::vector<Student*> Course::getEnrolledStudents() const {
    return enrolledStudents;
}

// Setters
void Course::setCourseName(const std::string& name) {
    this->courseName = name;
}

void Course::setInstructor(const std::string& instructor) {
    this->instructor = instructor;
}

void Course::setCredits(int credits) {
    this->credits = credits;
}

void Course::setMaxCapacity(int capacity) {
    this->maxCapacity = capacity;
}

// Student management
bool Course::addStudent(Student* student) {
    if (student == nullptr) {
        return false;
    }
    
    // Check if course is full
    if (isFull()) {
        std::cout << "Course is at maximum capacity!" << std::endl;
        return false;
    }
    
    // Check if student is already enrolled
    if (isStudentEnrolled(student->getStudentId())) {
        std::cout << "Student is already enrolled in this course!" << std::endl;
        return false;
    }
    
    enrolledStudents.push_back(student);
    return true;
}

bool Course::removeStudent(int studentId) {
    auto it = std::find_if(enrolledStudents.begin(), enrolledStudents.end(),
                          [studentId](const Student* student) {
                              return student->getStudentId() == studentId;
                          });
    
    if (it != enrolledStudents.end()) {
        enrolledStudents.erase(it);
        return true;
    }
    return false;
}

bool Course::isStudentEnrolled(int studentId) const {
    return std::any_of(enrolledStudents.begin(), enrolledStudents.end(),
                      [studentId](const Student* student) {
                          return student->getStudentId() == studentId;
                      });
}

bool Course::isFull() const {
    return enrolledStudents.size() >= static_cast<size_t>(maxCapacity);
}

void Course::displayCourseInfo() const {
    std::cout << "\n=== Course Information ===" << std::endl;
    std::cout << "Course ID: " << courseId << std::endl;
    std::cout << "Course Name: " << courseName << std::endl;
    std::cout << "Instructor: " << instructor << std::endl;
    std::cout << "Credits: " << credits << std::endl;
    std::cout << "Capacity: " << enrolledStudents.size() << "/" << maxCapacity << std::endl;
}

void Course::displayEnrolledStudents() const {
    std::cout << "\n=== Enrolled Students in " << courseName << " ===" << std::endl;
    if (enrolledStudents.empty()) {
        std::cout << "No students enrolled." << std::endl;
        return;
    }

    std::cout << std::left << std::setw(12) << "Student ID"
              << std::setw(25) << "Name"
              << std::setw(30) << "Email"
              << std::setw(15) << "Major" << std::endl;
    std::cout << std::string(82, '-') << std::endl;

    for (const auto& student : enrolledStudents) {
        std::cout << std::left << std::setw(12) << student->getStudentId()
                  << std::setw(25) << student->getName()
                  << std::setw(30) << student->getEmail()
                  << std::setw(15) << student->getMajor() << std::endl;
    }
}

// Destructor
Course::~Course() {
    // Clean up is handled by the system
}

