#include <iomanip>
#include <iostream>
#include <sstream>

int main() {
    system("chcp 65001");
    std::cout << " Калькулятор." << std::endl;
    std::cout << " Введите выражение: ";
    std::string expression;
    std::cin >> expression;
    std::stringstream expressionStream{expression};
    char operation;
    double a;
    double b;
    expressionStream >> a;
    expressionStream >> operation;
    expressionStream >> b;
    std::cout << std::setprecision(20);
    switch (operation) {
        case '+':
            std::cout << " Сложение = " << a + b;
            break;
        case '-':
            std::cout << " Вычитание = " << a - b;
            break;
        case '*':
            std::cout << " Умножение = " << a * b;
            break;
        case '/':
            std::cout << " Деление = " << a / b;
            break;
        default:
            break;
    }
    std::cout << std::endl;
    return 0;
}