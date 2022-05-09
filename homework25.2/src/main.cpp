#include <iostream>
#include "kbd.h"
#include "gpu.h"
#include "disk.h"
#include "cpu.h"
#include "main.h"

int main() {
    system("chcp 65001");
    std::cout << "Проект симулятора работы компьютера." << std::endl;
    std::cout << "Введите команду: ";
    std::string comand;
    double buffer[n];
    bool error;
    std::cin >> comand;
    while (comand != "exit") {
        if (comand == "sum") {
            std::cout << "Сумма = " << compute(buffer, n) << std::endl;
        } else if (comand == "save") {
            save(buffer, n);
        } else if (comand == "load") {
            load(buffer, n);
        } else if (comand == "input") {
            error = input(buffer, n);
            if (error) return -1;
        } else if (comand == "display") {
            display(buffer, n);
        } else std::cout << "Неизвестная команда, повторите ввод!" << std::endl;
        std::cout << std::endl;
        std::cout << "Введите команду: ";
        std::cin >> comand;
    }
    return 0;
}
