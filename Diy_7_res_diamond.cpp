#include <iostream>
#include <string>

class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(std::string n, int i) : name(n), id(i) {}

    void displayBase() const {
        std::cout << "ID: " << id << ", Name: " << name;
    }
};

class Manager : public Employee {
private:
    int teamSize;

public:
    Manager(std::string n, int i, int tSize) : Employee(n, i), teamSize(tSize) {}

    void printDetails() const {
        std::cout << "[Manager] ";
        displayBase();
        std::cout << ", Team Size: " << teamSize << "\n";
    }
};

class Engineer : public Employee {
private:
    std::string skill;

public:
    Engineer(std::string n, int i, std::string sk) : Employee(n, i), skill(sk) {}

    void printDetails() const {
        std::cout << "[Engineer] ";
        displayBase();
        std::cout << ", Primary Skill: " << skill << "\n";
    }
};

int main() {
    Manager mgr("Alice", 101, 12);
    Engineer eng("Bob", 102, "C++ Systems");

    mgr.printDetails();
    eng.printDetails();

    return 0;
}