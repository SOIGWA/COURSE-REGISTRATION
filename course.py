class Course:
    def __init__(self, course_id, name, instructor, credits, max_capacity):
        self.course_id = course_id
        self.name = name
        self.instructor = instructor
        self.credits = credits
        self.max_capacity = max_capacity
        self.enrolled_students = []
    
    def add_student(self, student):
        if len(self.enrolled_students) < self.max_capacity:
            if student not in self.enrolled_students:
                self.enrolled_students.append(student)
                return True
        return False
    
    def remove_student(self, student):
        if student in self.enrolled_students:
            self.enrolled_students.remove(student)
            return True
        return False
    
    def is_full(self):
        return len(self.enrolled_students) >= self.max_capacity
    
    def display_info(self):
        print(f"\n--- Course Information ---")
        print(f"Course ID: {self.course_id}")
        print(f"Name: {self.name}")
        print(f"Instructor: {self.instructor}")
        print(f"Credits: {self.credits}")
        print(f"Enrollment: {len(self.enrolled_students)}/{self.max_capacity}")
        
        if self.enrolled_students:
            print("\nEnrolled Students:")
            for student in self.enrolled_students:
                print(f"  - {student.name} ({student.student_id})")
