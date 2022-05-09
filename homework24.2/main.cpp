#include <iostream>
#include <ctime>
#include <map>
#include <iomanip>
#include <string>

int main() {
    system("chcp 65001");
    std::cout << " Реализация программы напоминания о днях рождения." << std::endl;
    std::multimap<std::time_t, std::string> friends;
    std::string name;
    std::cout << " Выход - end" << std::endl;
    std::cout << " Введите имя друга: ";
    std::cin >> name;
    while (name != "end") {
        std::time_t t = std::time(nullptr);
        std::tm birthday = *std::localtime(&t);
        std::cout << " Введите дату дня рождения -> 'ГГГГ/ММ/ДД': ";
        std::cin >> std::get_time(&birthday, "%Y/%m/%d");
        if (std::cin.fail()) {
            std::cerr << " Некорректный формат даты!";
            return -1;
        }
        std::time_t a = mktime(&birthday);
        friends.insert(std::pair<std::time_t, std::string>(a, name));
        std::cout << " Введите имя друга: ";
        std::cin >> name;
    }
    std::time_t d = std::time(nullptr);
    std::tm date = *std::localtime(&d);
    std::map<std::time_t, std::string>::iterator it;
    for (it = friends.begin(); it != friends.end(); ++it) {
        std::tm day = *std::localtime(&it->first);
        if (day.tm_mon == date.tm_mon && day.tm_mday == date.tm_mday) {
            std::cout << " Сегодня день рождения у " << it->second << "!" << std::endl;
        } else if ((day.tm_mon == date.tm_mon && day.tm_mday > date.tm_mday) || day.tm_mon > date.tm_mon) {
            std::cout << " Ближайший день рождения у " << it->second << " " << std::put_time(&day, "%m/%d") << std::endl;
            break;
        }
    }
}