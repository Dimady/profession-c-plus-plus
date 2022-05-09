#include <fstream>
#include <iostream>

int main() {
    system("chcp 65001");
    std::cout << std::endl;
    std::cout << " Введите имя файла с путем: ";
    std::string filename;
    std::cin >> filename;
    std::string sub = filename.substr(filename.size() - 4);
    if (sub != ".png") {
        std::cout << " Ошибка: неверный формат файла!" << std::endl;
        return -1;
    }
    std::ifstream pngFile(filename, std::ios::binary);
    if (!pngFile) {
        std::cout << " Ошибка: не удалось открыть файл для чтения!" << std::endl;
        return -1;
    }
    char buf[4];
    pngFile.read(buf, sizeof(buf));
    std::cout << (-119 == buf[0] && 'P' == buf[1] && 'N' == buf[2] && 'G' == buf[3]
             ? " Файл png является допустимым."
             : " Ошибка: этот файл не является файлом png.");
    pngFile.close();
    std::cout << std::endl;
    return 0;
}