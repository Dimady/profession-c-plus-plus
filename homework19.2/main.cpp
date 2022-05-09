#include <fstream>
#include <iostream>

int main() {
    system("chcp 65001");
    std::cout << " Введите путь к текстовому файлу:";
    std::string path = "C:\\skillbox\\profession-c-plus-plus\\homework19.2\\words.txt";
    std::cin >> path;
    std::cout << std::endl;
    std::ifstream file(path, std::ios::binary);
    if (!file) {
        std::cout << " Ошибка: не удалось открыть файл для чтения!";
        return 1;
    }
    while (file) {
        char text[20];
        file.read(text, sizeof(text) - 1);
        text[file.gcount()] = '\0';
        std::cout << text;
    }
    file.close();
    std::cout << std::endl;
    return 0;
}