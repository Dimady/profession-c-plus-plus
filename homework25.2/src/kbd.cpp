#include <iostream>
#include "kbd.h"

bool input(double *arr, int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << "Введите " << i + 1 << " число: ";
        std::cin >> arr[i];
        if (std::cin.fail()) {
            std::cerr << "Некорректный ввод данных!" << std::endl;
            return true;
        }
    }
    return false;
}