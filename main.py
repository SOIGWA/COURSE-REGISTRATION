
from registration_system import RegistrationSystem

def display_menu():
    print("\n" + "="*40)
    print("COURSE REGISTRATION SYSTEM")
    print("="*40)
    print("1. Add Student")
    print("2. Add Course")
    print("3. Register Student for Course")
    print("4. Drop Student from Course")
    print("5. View All Students")
    print("6. View All Courses")
    print("7. View Student Details")
    print("8. View Course Details")
    print("9. Exit")
    print("-"*40)

def add_student_handler(system):
    name = input("Enter student name: ")
    email = input("Enter student email: ")
    major = input("Enter student major: ")
    system.add_student(name, email, major)

def add_course_handler(system):
    name = input("Enter course name: ")
    instructor = input("Enter instructor name: ")
    credits = int(input("Enter credits: "))
    capacity = int(input("Enter max capacity: "))
    system.add_course(name, instructor, credits, capacity)

def register_student_handler(system):
    student_id = int(input("Enter student ID: "))
    course_id = int(input("Enter course ID: "))
    system.register_student(student_id, course_id)

def drop_student_handler(system):
    student_id = int(input("Enter student ID: "))
    course_id = int(input("Enter course ID: "))
    system.drop_student(student_id, course_id)

def view_all_students_handler(system):
    system.display_all_students()

def view_all_courses_handler(system):
    system.display_all_courses()

def view_student_details_handler(system):
    student_id = int(input("Enter student ID: "))
    student = system.get_student(student_id)
    if student:
        student.display_info()
    else:
        print("Student not found!")

def view_course_details_handler(system):
    course_id = int(input("Enter course ID: "))
    course = system.get_course(course_id)
    if course:
        course.display_info()
    else:
        print("Course not found!")

def exit_handler(system):
    print("Thank you for using the Course Registration System!")
    return True

def main():
    system = RegistrationSystem()
    
    # Add some sample data
    print("Setting up sample data...")
    system.add_student("Alice Kosgei", "alicekosgei@email.com", "Computer Science")
    system.add_student("Bob Mwangi", "bobmwangi@email.com", "Mathematics")
    system.add_course("Python Programming", "Dr. Wilson", 3, 25)
    system.add_course("Data Structures", "Prof. Davis", 4, 30)
    
    # Hash map (dictionary) to map menu choices to handler functions
    menu_handlers = {
        "1": add_student_handler,
        "2": add_course_handler,
        "3": register_student_handler,
        "4": drop_student_handler,
        "5": view_all_students_handler,
        "6": view_all_courses_handler,
        "7": view_student_details_handler,
        "8": view_course_details_handler,
        "9": exit_handler
    }
    
    while True:
        display_menu()
        choice = input("Enter your choice (1-9): ").strip()
        
        if choice in menu_handlers:
            # Call the appropriate handler function
            should_exit = menu_handlers[choice](system)
            if should_exit:  # Only exit_handler returns True
                break
        else:
            print("Invalid choice! Please try again.")

if __name__ == "__main__":
    main()
