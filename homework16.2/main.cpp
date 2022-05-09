#include <iostream>
#include <iomanip>

bool isNumber(std::string number) {
        for (char c: number)
            if (std::isdigit(c) == 0) return false;
        return true;
    }

int main() {
    system("chcp 65001");
    std::cout << " Сшиватель дробных чисел." << std::endl;
    std::string realNumber;
    std::string temp;
    std::cout << " Введите целую часть числа: ";
    std::cin >> temp;
    if (!isNumber(temp)) {
        std::cout << " Ошибка: неопределённый результат." << std::endl;
        return -1;
    }
    realNumber = temp + '.';
    std::cout << " Введите дробную часть числа:";
    std::cin >> temp;
    if (!isNumber(temp)) {
        std::cout << " Ошибка: неопределённый результат." << std::endl;
        return -1;
    }
    realNumber += temp;
    std::cout << " Действительное число: " << std::setprecision(20) << std::stod(realNumber);
    std::cout << std::endl;
    return 0;
}