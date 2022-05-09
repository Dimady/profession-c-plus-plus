#include <iostream>

constexpr int size = 15;
float numbers[size];

void sort() {
    float temp;
    for (int i = 0; i < size; i++) {
        for (int j = 1; j < size - i; j++) {
            if (numbers[j - 1] > numbers[j]) {
                temp = numbers[j - 1];
                numbers[j - 1] = numbers[j];
                numbers[j] = temp;
            }
        }
    }
}

int main() {
    system("chcp 65001");
    std::cout << " Сортировка." << std::endl;
    std::cout << " Введите " << size << " вещественных чисел." << std::endl;
    for (int i = 1; i < size; i++) {
        std::cin >> numbers[i];
    }
    sort();
    std::cout << " Вывод: ";
    for (int i = 1; i < size; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}
