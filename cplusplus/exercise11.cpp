#include <iostream>
#include <string>
#include <algorithm>

struct person_t{

    std::string name;
    int age;
    int id;

};

void print_person(const person_t *person);

bool compare_persons_by_id(const person_t *p1, const person_t *p2);

int main()
{
    person_t persons[3];

    for(int i = 0; i < 3; i++)
    {
    std::cout << "Enter details for person " << (i + 1) << ":\n";
    std::cout << "Name: ";
    std::cin >> persons[i].name;
    std::cout << "Age: ";
    std::cin >> persons[i].age;
    std::cout << "ID: ";
    std::cin >> persons[i].id;
    }
    // Sort the persons array by ID using pointers and the compare function
    std::sort(persons, persons + 3, [](const person_t &p1, const person_t &p2)
              { return p1.id < p2.id; });

    // Print the sorted persons using pointers
    std::cout << "\nSorted persons by ID:\n";
    for (int i = 0; i < 3; ++i)
    {
        print_person(&persons[i]);
    }
}

void print_person(const person_t *person)
{
    std::cout << "Name: " << person->name << ", Age: " << person->age << ", ID: " << person->id << std::endl;
}

// Function to compare two persons by id (for sorting)
bool compare_persons_by_id(const person_t *p1, const person_t *p2)
{
    return p1->id < p2->id;
}
