#include <iostream>
#include <string>

class Person {
protected:
    std::string name;

public:
    Person(std::string n = "Unknown") : name(n) {
        std::cout << "Person constructor called for: " << name << "\n";
    }
};

// Virtual inheritance prevents duplicate Person subobjects
class Student : virtual public Person {
protected:
    int studentId;

public:
    Student(std::string n, int sId) : Person(n), studentId(sId) {}
};

class Employee : virtual public Person {
protected:
    int empId;

public:
    Employee(std::string n, int eId) : Person(n), empId(eId) {}
};

class TA : public Student, public Employee {
private:
    std::string course;

public:
    // Most derived class initializes the virtual base class directly
    TA(std::string n, int sId, int eId, std::string c)
        : Person(n), Student(n, sId), Employee(n, eId), course(c) {}

    void display() const {
        // No ambiguity when accessing 'name' because only one Person copy exists
        std::cout << "TA Name: " << name 
                  << " | Student ID: " << studentId 
                  << " | Employee ID: " << empId 
                  << " | Course: " << course << "\n";
    }
};

int main() {
    TA ta("Charlie", 5001, 9001, "CS101");
    ta.display();
    return 0;
}