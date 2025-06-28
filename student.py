class Student:
    def __init__(self, student_id, name, email, major):
        self.student_id = student_id
        self.name = name
        self.email = email
        self.major = major
        self.enrolled_courses = []
    
    def enroll_in_course(self, course):
        if course not in self.enrolled_courses:
            self.enrolled_courses.append(course)
            return True
        return False
    
    def drop_course(self, course):
        if course in self.enrolled_courses:
            self.enrolled_courses.remove(course)
            return True
        return False
    
    def display_info(self):
        print(f"\n--- Student Information ---")
        print(f"ID: {self.student_id}")
        print(f"Name: {self.name}")
        print(f"Email: {self.email}")
        print(f"Major: {self.major}")
        print(f"Enrolled Courses: {len(self.enrolled_courses)}")
        
        if self.enrolled_courses:
            print("\nEnrolled Courses:")
            for course in self.enrolled_courses:
                print(f"  - {course.name} ({course.course_id})")
