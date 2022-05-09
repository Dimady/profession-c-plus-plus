#pragma once
#include <vector>

class Manager;
class Employee;


class Boss
{
    int _countManager{0};
    unsigned int _countAWork{0};
    std::vector<Manager *> manager;

public:
    Boss(const int countManager = 0);
    ~Boss();
    int addManager(const int countManager);
    int getCountManager();
    Employee* addAnEmployeeToAManager(const int managerId);
    unsigned int setDirectorsDerective(unsigned int directive);
};