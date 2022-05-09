#include <iostream>
#include <string>

int main() {
    system("chcp 65001");
    constexpr int size = 10;
    std::string name[size];
    std::string a[3];
    std::string alphabet = "12345678910";
    int index, b;
    std::cout << " Многоквартирный дом." << std::endl;
    std::cout << " Введите " << size << " фамилий жильцов." << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << ": ";
        std::cin >> name[i];
    }
    std::cout << " Введите три номера квартир." << std::endl;
    for (int i = 0; i < 3; i++) {
        std::cout << i + 1 << ": ";
        std::cin >> a[i];
        index = alphabet.find(a[i]);
        b = std::stoi(a[i]);
        if (index < 0 || b < 1 || b > 10) {
            std::cout << " Некорректный ввод данных. Повторите ввод." << std::endl;
            i--;
            continue;
        }
        std::cout << name[b - 1] << std::endl;
    }
    return 0;
}
