#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

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
class Stack
{
private:
    std::vector<Student<T> *> stack; // Vector to store Student pointers (stack)

public:
    // Function to add (push) a student onto the stack
    void push(Student<T> *student)
    {
        stack.push_back(student); // Add student to the stack (vector)
    }

    // Function to remove (pop) the top student from the stack
    Student<T> *pop()
    {
        if (stack.empty())
        {
            throw std::out_of_range("Stack underflow: No students to pop.");
        }
        Student<T> *topStudent = stack.back();
        stack.pop_back();
        return topStudent;
    }

    // Function to get the student at the top of the stack without removing it
    Student<T> *peek() const
    {
        if (stack.empty())
        {
            throw std::out_of_range("Stack is empty.");
        }
        return stack.back();
    }

    // Function to check if the stack is empty
    bool isEmpty() const
    {
        return stack.empty();
    }

    // Function to print all students in the stack
    void printAllStudents() const
    {
        for (const Student<T> *student : stack)
        {
            student->printInfo();
            std::cout << "----------------------------" << std::endl;
        }
    }
};

int main()
{
    try
    {
        // Create a Stack for integer grades
        Stack<int> stack;

        // Create students
        Student<int> student1("John Doe", "S1001");
        Student<int> student2("Jane Smith", "S1002");

        // Push students onto the stack
        stack.push(&student1);
        stack.push(&student2);

        // Add grades to students
        student1.addGrade(90);
        student1.addGrade(85);
        student2.addGrade(92);
        student2.addGrade(78);

        // Print all students in the stack
        std::cout << "Students in Stack:" << std::endl;
        stack.printAllStudents();

        // Pop the top student (student2) from the stack
        Student<int> *topStudent = stack.pop();
        std::cout << "\nPopped student:" << std::endl;
        topStudent->printInfo();

        // Print remaining students in the stack
        std::cout << "\nRemaining students in Stack:" << std::endl;
        stack.printAllStudents();

        // Create another Stack for floating-point grades
        Stack<double> stackFloat;

        // Create students
        Student<double> student3("Alice Brown", "S1003");
        Student<double> student4("Bob White", "S1004");

        // Push students onto the stack
        stackFloat.push(&student3);
        stackFloat.push(&student4);

        // Add floating-point grades to students
        student3.addGrade(90.5);
        student3.addGrade(85.7);
        student4.addGrade(92.3);
        student4.addGrade(78.9);

        // Print all students in the float stack
        std::cout << "\nStudents in Float Stack:" << std::endl;
        stackFloat.printAllStudents();

        // Pop the top student (student4) from the float stack
        Student<double> *topStudentFloat = stackFloat.pop();
        std::cout << "\nPopped student from float stack:" << std::endl;
        topStudentFloat->printInfo();

        // Print remaining students in the float stack
        std::cout << "\nRemaining students in Float Stack:" << std::endl;
        stackFloat.printAllStudents();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}
