#include <cmath>
#include <iostream>

struct Coordinates {
    double x = 0;
    double y = 0;
};

std::ostream& operator << (std::ostream& out, const Coordinates& coord) {
    out << coord.x << " " << coord.y << std::endl;
    return out;
}

Coordinates operator + (const Coordinates& one, const Coordinates& two) {
    Coordinates coordOut;
    coordOut.x = one.x + two.x;
    coordOut.y = one.y + two.y;
    return coordOut;
}

Coordinates operator - (const Coordinates& one, const Coordinates& two) {
    Coordinates coordOut;
    coordOut.x = one.x - two.x;
    coordOut.y = one.y - two.y;
    return coordOut;
}

Coordinates operator * (const Coordinates& coord, const double& scalar) {
    Coordinates coordOut;
    coordOut.x = coord.x * scalar;
    coordOut.y = coord.y * scalar;
    return coordOut;
}

void add() {
    std::cout << " Введите координаты первого вектора: ";
    Coordinates one;
    std::cin >> one.x >> one.y;
    std::cout << " Введите координаты второго вектора: ";
    Coordinates two;
    std::cin >> two.x >> two.y;
    std::cout << " Новый вектор: " << one + two << std::endl;
}

void subtract() {
    std::cout << " Введите координаты первого вектора: ";
    Coordinates one;
    std::cin >> one.x >> one.y;
    std::cout << " Введите координаты второго вектора:";
    Coordinates two;
    std::cin >> two.x >> two.y;
    std::cout << " Новый вектор: " << one - two << std::endl;
}

void scale() {
    std::cout << " Введите координаты вектора: ";
    Coordinates coord;
    std::cin >> coord.x >> coord.y;
    std::cout << " Введите скаляр: ";
    int32_t scalar;
    std::cin >> scalar;
    std::cout << " Новый вектор: " << coord * scalar << std::endl;
}

double length(Coordinates& coord) {
    return std::sqrt(coord.x * coord.x + coord.y * coord.y);
}

void normalize() {
    std::cout << " Введите координаты вектора: ";
    Coordinates coord;
    std::cin >> coord.x >> coord.y;
    double inverseLength = 1 / length(coord);
    std::cout << " Вектор после нормализации: " << coord * inverseLength << std::endl;
}

int main() {
    system("chcp 65001");
    int command;
    std::cout << " Реализация математического вектора." << std::endl;
    std::cout << " Введите 1, чтобы сложить два вектора" << std::endl;
    std::cout << " Введите 2, чтобы вычесть два вектора" << std::endl;
    std::cout << " Введите 3 для умножения вектора на скаляр" << std::endl;
    std::cout << " Введите 4, чтобы найти длину вектора" << std::endl;
    std::cout << " Введите 5, чтобы нормализовать вектор" << std::endl;
    std::cin >> command;
    Coordinates coord;
    switch (command) {
        case 1:
            add();
            break;
        case 2:
            subtract();
            break;
        case 3:
            scale();
            break;
        case 4:
            std::cout << " Введите координаты вектора:";
            std::cin >> coord.x >> coord.y;
            std::cout << " Длина вектора: " << length(coord) << std::endl;
            break;
        case 5:
            normalize();
            break;
        default:
            std::cerr << " Неопределённая команда!" << std::endl;
            break;
    }
    std::cout << std::endl;
    return 0;
}
