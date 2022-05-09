#include <iostream>
#include "struct.h"

int main()
{
    system("chcp 65001");
    std::cout << "Симулятор проведения операций." << std::endl;
    std::cout << "Приступаем к операции." << std::endl;
    std::cout << "Введите команду: ";
    std::string comand;
    bool error;
    std::cin >> comand;
    while (comand != "scalpel") {
        std::cout << "Неизвестная команда, попробуйте еще раз!" << std::endl;
        std::cout << "Введите команду: ";
        std::cin >> comand;
    }
    instrument operation;
    std::cout << "Введите координаты начала: ";
    error = input(&operation.scalpel[0], &operation.scalpel[1]);
    if (error) return -1;
    std::cout << "Введите координаты конца: ";
    error = input(&operation.scalpel[2], &operation.scalpel[3]);
    if (error) return -1;
    output("Надрез", operation.scalpel[0], operation.scalpel[1], operation.scalpel[2], operation.scalpel[3]);
    std::cout << "Введите команду: ";
    std::cin >> comand;
    while (comand != "end") {
        if (comand == "hemostat") {
            std::cout << "Введите координаты: ";
            error = input(&operation.hemostat[0], &operation.hemostat[1]);
            if (error) return -1;
            output("Зажим", operation.hemostat[0], operation.hemostat[1]);
            std::cout << "Введите команду: ";
            std::cin >> comand;
        }
        else if (comand == "tweezers") {
            std::cout << "Введите координаты: ";
            error = input(&operation.tweezers[0], &operation.tweezers[1]);
            if (error) return -1;
            output("Пинцет", operation.tweezers[0], operation.tweezers[1]);
            std::cout << "Введите команду: ";
            std::cin >> comand;
        }
        else if (comand == "suture") {
            bool suture = false;
            while (!suture) {
                std::cout << "Введите координаты начала: ";
                error = input(&operation.suture[0], &operation.suture[1]);
                if (error) return -1;
                std::cout << "Введите координаты конца: ";
                error = input(&operation.suture[2], &operation.suture[3]);
                if (error) return -1;
                suture = equal(operation.suture, operation.scalpel);
            }
            output("Шов", operation.suture[0], operation.suture[1], operation.suture[2], operation.suture[3]);
            std::cout << "Операция успешно завершена!" << std::endl;
            comand = "end";
        }
        else {
            std::cout << "Неизвестная команда, попробуйте еще раз!" << std::endl;
            std::cout << "Введите команду: ";
            std::cin >> comand;
        }
    }
    return 0;
}