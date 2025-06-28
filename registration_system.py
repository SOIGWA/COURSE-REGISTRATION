from student import Student
from course import Course

class RegistrationSystem:
    def __init__(self):
        self.students = {}
        self.courses = {}
        self.next_student_id = 1001
        self.next_course_id = 101
    
    def add_student(self, name, email, major):
        student_id = self.next_student_id
        student = Student(student_id, name, email, major)
        self.students[student_id] = student
        self.next_student_id += 1
        print(f"Student {name} added with ID: {student_id}")
        return student_id
    
    def add_course(self, name, instructor, credits, max_capacity):
        course_id = self.next_course_id
        course = Course(course_id, name, instructor, credits, max_capacity)
        self.courses[course_id] = course
        self.next_course_id += 1
        print(f"Course {name} added with ID: {course_id}")
        return course_id
    
    def register_student(self, student_id, course_id):
        if student_id not in self.students:
            print("Student not found!")
            return False
        
        if course_id not in self.courses:
            print("Course not found!")
            return False
        
        student = self.students[student_id]
        course = self.courses[course_id]
        
        if course.is_full():
            print("Course is full!")
            return False
        
        if course.add_student(student) and student.enroll_in_course(course):
            print(f"{student.name} successfully registered for {course.name}")
            return True
        else:
            print("Registration failed - student already enrolled!")
            return False
    
    def drop_student(self, student_id, course_id):
        if student_id not in self.students or course_id not in self.courses:
            print("Student or course not found!")
            return False
        
        student = self.students[student_id]
        course = self.courses[course_id]
        
        if course.remove_student(student) and student.drop_course(course):
            print(f"{student.name} dropped from {course.name}")
            return True
        else:
            print("Drop failed!")
            return False
    
    def display_all_students(self):
        print("\n=== ALL STUDENTS ===")
        if not self.students:
            print("No students registered.")
            return
        
        for student in self.students.values():
            print(f"{student.student_id}: {student.name} ({student.major}) - {len(student.enrolled_courses)} courses")
    
    def display_all_courses(self):
        print("\n=== ALL COURSES ===")
        if not self.courses:
            print("No courses available.")
            return
        
        for course in self.courses.values():
            print(f"{course.course_id}: {course.name} - {course.instructor} - {len(course.enrolled_students)}/{course.max_capacity} students")
    
    def get_student(self, student_id):
        return self.students.get(student_id)
    
    def get_course(self, course_id):
        return self.courses.get(course_id)