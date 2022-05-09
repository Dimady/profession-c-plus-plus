#include <iostream>

constexpr int size = 15;
int numbers[size];

int main() {
    system("chcp 65001");
    int y, x = 105, min, sum0 = 0, sum = 0;
    std::cout << " Ряд чисел." << std::endl;
    std::cout << " X = " << x << std::endl;
    for (int i = 0; i < size - 1; i++) {
        numbers[i] = x + i;
    }
    numbers[size - 1] = x + rand() / 10;
    min = numbers[0];
    for (int i = 0; i < size - 1; i++) sum0 += i;
    for (int i = 0; i < size; i++) {
        if (numbers[i] < min) min = numbers[i];
        sum += numbers[i];
    }
    y = sum - (sum0 + (size - 1) * min);
    std::cout << " Повторяющееся число: " << y << std::endl;
    return 0;
}
