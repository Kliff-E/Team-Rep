#include <iostream>
#include <string>
#include <stdexcept>

template <typename T>
class Student
{
private:
    std::string name;
    std::string studentID;
    T grades[5];    // Fixed size array for grades, assuming a maximum of 5 grades for simplicity
    int gradeCount; // Keeps track of the number of grades entered

public:
    // Constructor to initialize student data
    Student(std::string name, std::string studentID)
        : name(name), studentID(studentID), gradeCount(0) {}

    // Function to add a grade
    void addGrade(T grade)
    {
        if (gradeCount < 5)
        {
            grades[gradeCount++] = grade; // Add the grade to the array
        }
        else
        {
            std::cout << "Cannot add more than 5 grades." << std::endl;
        }
    }

    // Function to calculate the average grade
    double getAverageGrade() const
    {
        if (gradeCount == 0)
            return 0.0;

        double sum = 0;
        for (int i = 0; i < gradeCount; i++)
        {
            sum += grades[i];
        }
        return sum / gradeCount;
    }

    // Function to print student information
    void printInfo() const
    {
        std::cout << "Name: " << name << std::endl;
        std::cout << "Student ID: " << studentID << std::endl;
        std::cout << "Grades: ";
        for (int i = 0; i < gradeCount; i++)
        {
            std::cout << grades[i] << " ";
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

// Node structure to represent each element in the queue
template <typename T>
struct Node
{
    Student<T> *student; // Pointer to the student object
    Node *next;          // Pointer to the next node in the queue
};

// Queue class using linked list
template <typename T>
class Queue
{
private:
    Node<T> *front; // Pointer to the front of the queue
    Node<T> *rear;  // Pointer to the rear of the queue

public:
    // Constructor to initialize the queue
    Queue() : front(nullptr), rear(nullptr) {}

    // Destructor to clean up memory
    ~Queue()
    {
        while (!isEmpty())
        {
            dequeue(); // Dequeue all students to free the memory
        }
    }

    // Function to add (enqueue) a student to the queue
    void enqueue(Student<T> *student)
    {
        Node<T> *newNode = new Node<T>;
        newNode->student = student;
        newNode->next = nullptr;

        if (rear == nullptr) // If the queue is empty
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Function to remove (dequeue) the front student from the queue
    Student<T> *dequeue()
    {
        if (isEmpty())
        {
            throw std::out_of_range("Queue underflow: No students to dequeue.");
        }

        Node<T> *temp = front;
        Student<T> *frontStudent = temp->student;
        front = front->next;

        if (front == nullptr) // If the queue becomes empty
        {
            rear = nullptr;
        }

        delete temp; // Free the node
        return frontStudent;
    }

    // Function to get the student at the front of the queue without removing it
    Student<T> *peek() const
    {
        if (isEmpty())
        {
            throw std::out_of_range("Queue is empty.");
        }
        return front->student;
    }

    // Function to check if the queue is empty
    bool isEmpty() const
    {
        return front == nullptr;
    }

    // Function to print all students in the queue
    void printAllStudents() const
    {
        Node<T> *current = front;
        while (current != nullptr)
        {
            current->student->printInfo();
            std::cout << "----------------------------" << std::endl;
            current = current->next;
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
