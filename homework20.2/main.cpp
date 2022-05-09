#include <ctime>
#include <fstream>
#include <iostream>

int main() {
    system("chcp  65001");
    std::cout << " Реализация рисования случайных картин." << std::endl;
    int height, width;
    std::cout << " Введите высоту и ширину: ";
    std::cin >> height >> width;
    std::ofstream pic("C:\\skillbox\\profession-c-plus-plus\\homework20.2\\pic.txt", std::ios::binary);
    if (!pic) {
        std::cout << " Ошибка: не удалось открыть файл для записи!" << std::endl;
        return -1;
    }
    std::srand(std::time(nullptr));
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) pic << rand() % 2 << " ";
        pic << std::endl;
    }
    pic.close();
    std::cout << std::endl;
    return 0;
}