#include "boss.h"
#include "manager.h"

Boss::Boss(const int countManager) : _countManager(countManager) {
}

int Boss::getCountManager() {
    return _countManager;
}

int Boss::addManager(const int countManager) {
    if(countManager <=0)
         return  _countManager = 0;
    _countManager = countManager;
    for(int i = 0; i < _countManager; ++i) {
        Manager* man = new Manager;
        manager.push_back(man);
    }
    return _countManager = manager.size();
}

Boss::~Boss() {
    for(auto man : manager)
        delete man;
}

Employee* Boss::addAnEmployeeToAManager(const int managerId) {
    return manager[managerId]->addEmployee();
}

unsigned int Boss::setDirectorsDerective(unsigned int directive) {
    _countAWork = 0;
    for (auto work : manager) {
            work->addTaskSize(directive);
            _countAWork += work->distributionOfTask();
        }
    return _countAWork;
}