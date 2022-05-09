#include <iostream>
#include "boss.h"
#include "manager.h"
#include "employee.h"

int main() {
    system("chcp 65001");
    Boss boss;
    std::cout << "Введите количество команд: ";
    int sizeTeams;
    std::cin >> sizeTeams;
    auto col = boss.addManager(sizeTeams);
    for(auto i = 0; i < col; ++i) {
        std::cout << "Введите количество сотрудников для команды #" << i << ": ";
        int sizeEmployee;
        std::cin >> sizeEmployee;
        for(int j = 0; j < sizeEmployee; ++j) {
            auto empl = boss.addAnEmployeeToAManager(i);
            empl->setName("Worker" + std::to_string(j));
        }
    }

    unsigned int awork;
    do {
        std::cout << "Введите директиву директора компании: ";
        unsigned int dir;
        std::cin >> dir;
        awork = boss.setDirectorsDerective(dir);
    } while (awork != 0);

    return 0;
}