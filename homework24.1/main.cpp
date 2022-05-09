#include <iostream>
#include <map>
#include <ctime>

void end (std::map <std::string, double> &map, std::string &str, std::time_t t){
    if (str == "") return;
    else {
        std::time_t finish = std::time(nullptr);
        double diff = std::difftime(finish, t);
        map.insert(std::pair<std::string, double>(str, diff));
        str = "";
    }
    return;
}

int main() {
    system("chcp 65001");
    std::cout << " Реализация программы учёта времени." << std::endl;
    std::map<std::string, double> task;
    std::string comand;
    std::time_t start = 0;
    std::string name = "";
    std::cout << " Введите команду: ";
    std::cin >> comand;
    while (comand != "exit") {
        if (comand == "begin") {
            if (start != 0) end(task, name, start);
            std::cout << " Введите название задачи: ";
            std::cin >> name;
            start = std::time(nullptr);
        }
        else if (comand == "end") {
            end(task, name, start);
        }
        else if (comand == "status") {
            for(std::map<std::string, double>::iterator it = task.begin(); it != task.end(); ++it) {
                int t = it->second;
                std::cout << it-> first << " " << t / 3600 <<" ч. " << (t % 3600) / 60 << " мин. " << t % 60  << " сек. " << std::endl;
            }
            if (name != "") std::cout << name << std::endl;
        }
        else std::cerr << "Неверная команда!" << std::endl;
        std::cout << " Введите команду: ";
        std::cin >> comand;
    }
    std::cout << std::endl;
    return 0;
}