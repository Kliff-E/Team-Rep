#include <iostream>
#include <string>
#include <vector>

template <typename T>
class Student
{
private:
    std::string name;
    std::string studentID;
    std::vector<T> grades; // Using a vector to store grades dynamically, template type T

public:
    // Constructor to initialize student data
    Student(std::string name, std::string studentID)
        : name(name), studentID(studentID) {}

    // Function to add a grade
    void addGrade(T grade)
    {
        grades.push_back(grade); // Dynamically add the grade to the vector
    }

    // Function to calculate the average grade
    double getAverageGrade() const
    {
        if (grades.empty())
            return 0.0;

        double sum = 0;
        for (T grade : grades)
        {
            sum += grade;
        }
        return sum / grades.size();
    }

    // Function to print student information
    void printInfo() const
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Student ID: " << studentID << std::endl;
        std::cout << "Grades: ";
        for (T grade : grades)
        {
            std::cout << grade << " ";
        }
        std::cout << std::endl;
        std::cout << "Average Grade: " << getAverageGrade() << std::endl;
    }

    // Getter for student ID
    std::string getStudentID() const
    {
        return studentID;
    }
};

template <typename T>
class StudentDatabase
{
private:
    std::vector<Student<T> *> students; // Using a vector of pointers to store students dynamically

public:
    // Add a student to the database
    void addStudent(Student<T> *student)
    {
        students.push_back(student); // Dynamically add student to the vector
    }

    // Add a grade to a student by student ID
    void addGradeToStudent(const std::string &studentID, T grade)
    {
        for (Student<T> *student : students)
        {
            if (student->getStudentID() == studentID)
            {
                student->addGrade(grade);
                return;
            }
        }
        std::cout << "Student with ID " << studentID << " not found!" << std::endl;
    }

    // Print information for all students
    void printAllStudents() const
    {
        for (const Student<T> *student : students)
        {
            student->printInfo();
            std::cout << "----------------------------" << std::endl;
        }
    }
};

int main()
{
    // Create a StudentDatabase for integer grades
    StudentDatabase<int> db;

    // Create students
    Student<int> student1("John Doe", "S1001");
    Student<int> student2("Jane Smith", "S1002");

    // Add students to the database
    db.addStudent(&student1);
    db.addStudent(&student2);

    // Add grades to students
    db.addGradeToStudent("S1001", 90);
    db.addGradeToStudent("S1001", 85);
    db.addGradeToStudent("S1002", 92);
    db.addGradeToStudent("S1002", 78);

    // Print all students' information
    db.printAllStudents();

    // Create a StudentDatabase for floating-point grades
    StudentDatabase<double> dbFloat;

    // Create students
    Student<double> student3("Alice Brown", "S1003");
    Student<double> student4("Bob White", "S1004");

    // Add students to the database
    dbFloat.addStudent(&student3);
    dbFloat.addStudent(&student4);

    // Add grades to students (floating-point grades)
    dbFloat.addGradeToStudent("S1003", 90.5);
    dbFloat.addGradeToStudent("S1003", 85.7);
    dbFloat.addGradeToStudent("S1004", 92.3);
    dbFloat.addGradeToStudent("S1004", 78.9);

    // Print all students' information
    dbFloat.printAllStudents();

    return 0;
}
