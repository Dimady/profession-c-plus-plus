#pragma once
#include <vector>
#include <ostream>

class Employee;

class Manager {
public:
    enum Task {
        A,
        B,
        C
    };
private:
    static unsigned int id;
    unsigned int _id{0};
    std::vector<Employee*> _team;
    int taskSize{0};
    unsigned int availableEmployees{0};
public:
    Manager();
    ~Manager();
    Employee* addEmployee();
    void addTaskSize(unsigned int directive);
    unsigned int distributionOfTask();
};