#pragma once

struct instrument {
    double scalpel[4];
    double hemostat[2];
    double tweezers[2];
    double suture[4];
};

bool input(double *a, double *b) {
    double temp1, temp2;
    std::cin >> temp1 >> temp2;
    if (std::cin.fail()) {
        std::cerr << "Ошибка ввода координат!" << std::endl;
        return true;
    }
    *a = temp1;
    *b = temp2;
    return false;
}

void output(std::string s, double a, double b) {
    std::cout << s << " с координатами (" << a << ", " << b << ")" << std::endl;
}

void output(std::string s, double a, double b, double c, double d) {
    std::cout << s << " с координатами (" << a << ", " << b << ") (" << c << ", " << d << ")" << std::endl;
}

bool equal(double *a, double *b) {
    for (int i = 0; i < 4; ++i) {
        if (a[i] - b[i] != 0) {
            std::cout << "Неправильные координаты, попробуйте еще раз!" << std::endl;
            return false;
        }
    }
    return true;
}