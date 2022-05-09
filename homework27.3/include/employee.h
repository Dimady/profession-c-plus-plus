#pragma once
#include <string>
#include "manager.h"

class Employee
{
    bool _work{false};
    std::string name{"no name"};
    Manager::Task _task;
public:
  
    bool isWork()
    {
        return _work;
    }
    void setTask(bool work, Manager::Task task)
    {
        _task = task;
        _work = true;
    }
    void setName(const std::string &name)
    {
        this->name = name;
    }
    void getTask(const unsigned int managerId)
    {
        std::string task;
        switch (_task)
        {
        case Manager::A:
            task = "A";
            break;
        case Manager::B:
            task = "B";
            break;
        case Manager::C:
            task = "C";
            break;
        default:
            break;
        }
        std::cout<<"Команда " << managerId << ": " << name << " выполняет задачу " << task << std::endl;
    }
};