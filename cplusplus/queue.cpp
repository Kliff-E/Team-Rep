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
class Queue
{
private:
    std::vector<Student<T> *> queue; // Vector to store Student pointers (queue)

public:
    // Function to add (enqueue) a student to the queue
    void enqueue(Student<T> *student)
    {
        queue.push_back(student); // Add student to the back of the queue
    }

    // Function to remove (dequeue) the front student from the queue
    Student<T> *dequeue()
    {
        if (queue.empty())
        {
            throw std::out_of_range("Queue underflow: No students to dequeue.");
        }
        Student<T> *frontStudent = queue.front();
        queue.erase(queue.begin()); // Remove student from the front of the queue
        return frontStudent;
    }

    // Function to get the student at the front of the queue without removing it
    Student<T> *peek() const
    {
        if (queue.empty())
        {
            throw std::out_of_range("Queue is empty.");
        }
        return queue.front();
    }

    // Function to check if the queue is empty
    bool isEmpty() const
    {
        return queue.empty();
    }

    // Function to print all students in the queue
    void printAllStudents() const
    {
        for (const Student<T> *student : queue)
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
        // Create a Queue for integer grades
        Queue<int> queue;

        // Create students
        Student<int> student1("John Doe", "S1001");
        Student<int> student2("Jane Smith", "S1002");

        // Enqueue students into the queue
        queue.enqueue(&student1);
        queue.enqueue(&student2);

        // Add grades to students
        student1.addGrade(90);
        student1.addGrade(85);
        student2.addGrade(92);
        student2.addGrade(78);

        // Print all students in the queue
        std::cout << "Students in Queue:" << std::endl;
        queue.printAllStudents();

        // Dequeue the front student (student1) from the queue
        Student<int> *frontStudent = queue.dequeue();
        std::cout << "\nDequeued student:" << std::endl;
        frontStudent->printInfo();

        // Print remaining students in the queue
        std::cout << "\nRemaining students in Queue:" << std::endl;
        queue.printAllStudents();

        // Create another Queue for floating-point grades
        Queue<double> queueFloat;

        // Create students
        Student<double> student3("Alice Brown", "S1003");
        Student<double> student4("Bob White", "S1004");

        // Enqueue students into the queue
        queueFloat.enqueue(&student3);
        queueFloat.enqueue(&student4);

        // Add floating-point grades to students
        student3.addGrade(90.5);
        student3.addGrade(85.7);
        student4.addGrade(92.3);
        student4.addGrade(78.9);

        // Print all students in the float queue
        std::cout << "\nStudents in Float Queue:" << std::endl;
        queueFloat.printAllStudents();

        // Dequeue the front student (student3) from the float queue
        Student<double> *frontStudentFloat = queueFloat.dequeue();
        std::cout << "\nDequeued student from float queue:" << std::endl;
        frontStudentFloat->printInfo();

        // Print remaining students in the float queue
        std::cout << "\nRemaining students in Float Queue:" << std::endl;
        queueFloat.printAllStudents();
    }
    catch (const std::exception &e)
    {
        std::cerr << "Exception occurred: " << e.what() << std::endl;
    }

    return 0;
}
