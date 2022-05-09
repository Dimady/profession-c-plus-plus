#include <cstdlib>
#include <iostream>
#include "employee.h"

unsigned int Manager::id{1};

Manager::Manager() {
   _id = id++;
}

Employee* Manager::addEmployee() {
   Employee * emp = new Employee;
   _team.push_back(emp);
   return emp;
}

Manager::~Manager() {
   for(auto &emp : _team)
      delete emp;
}

void Manager::addTaskSize(unsigned int derective) {
   std::srand(_id + derective);
   taskSize = std::rand() % _team.size() + 1;
}

unsigned int Manager::distributionOfTask() {
   if(availableEmployees >= _team.size()) {
      std::cout << "В команде #" << _id << " все сотрудники заняты" << std::endl;
      return 0;
   }
      
   for(int i = 0, j = 0; i < taskSize && j < _team.size(); ++j) {
      if(!_team[j]->isWork()) {
          _team[j]->setTask(true, static_cast<Manager::Task>(std::rand() % 3));
          ++availableEmployees;
          ++i;
          _team[j]->getTask(_id);
      }     
   }
   return availableEmployees;
}