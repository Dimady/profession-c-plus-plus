#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>

bool isEqualFloat(double a, double b, double absEpsilon) {
    if (fabs(a - b) <= absEpsilon) return true;
    return false;
}

int main() {
    system("chcp 65001");
    std::cout << " Спидометр." << std::endl;
    std::stringstream speedometr;
    double currentSpeed = 0.;
    double speed;
    do {
        std::cout << " Введите разницу скорости: ";
        std::cin >> speed;
        currentSpeed += speed;
        if (currentSpeed > 150 || isEqualFloat(currentSpeed, 150., 0.01)) {
            std::cout << " Это больше, чем максимальная скорость! Замедлите!" << std::endl;
            currentSpeed -= speed;
            continue;
        }
        if (currentSpeed < 0 || isEqualFloat(currentSpeed, 0., 0.01)) {
            speedometr << 0. << std::endl;
        break;
        }
        speedometr << std::fixed << std::setprecision(2) << currentSpeed << " км/ч" << std::endl;
        std::cout << " Текущая скорость: " << std::fixed << std::setprecision(2) << currentSpeed << std::endl;
  } while (true);
  std::cout << std::endl;
  std::cout << speedometr.str();
  std::cout << std::endl;
  return 0;
}