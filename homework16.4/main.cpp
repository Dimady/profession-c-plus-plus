#include <iostream>
#include <sstream>
enum class Piano {
    DO = 1 << 0,
    RE = 1 << 1,
    MI = 1 << 2,
    FA = 1 << 3,
    SO = 1 << 4,
    LA = 1 << 5,
    SI = 1 << 6,
    };

void printNotes(const std::string noteCombination) {
    for (int i = 0; i < noteCombination.length(); ++i) {
        int note = noteCombination[i] - '0';
        std::cout << std::endl;
        switch (1 << (note - 1)) {
            case int(Piano::DO):
                std::cout << "Do";
                break;
            case int(Piano::RE):
                std::cout << "Re";
                break;
            case int(Piano::MI):
                std::cout << "Mi";
                break;
            case int(Piano::FA):
                std::cout << "Fa";
                break;
            case int(Piano::SO):
                std::cout << "So";
                break;
            case int(Piano::LA):
                std::cout << "La";
                break;
            case int(Piano::SI):
                std::cout << "Si";
                break;
        }
    }
    std::cout << std::endl;
}

bool checkNoteCombination(std::string noteCombination) {
    for (int i = 0; i < noteCombination.length(); ++i) {
        if (noteCombination[i] < '1' || noteCombination[i] > '7') {
            std::cout << " Ошибка! Некорректные ноты." << std::endl;
            return false;
        }
    }
    return true;
}

int main() {
    system("chcp 65001");
    std::cout << " Механическое пианино." << std::endl;
    std::stringstream musicNotation;
    std::string noteCombination;
    for (int i = 0; i < 12; ++i) {
        std::cout << " Введите музыкальную комбинацию: ";
        std::cin >> noteCombination;
        if (!checkNoteCombination(noteCombination)) continue;

        musicNotation << noteCombination << " ";
    }
    std::cout << " Ваше музыкальное произведение:: " << std::endl;
    for (int i = 0; i < 12; ++i) {
        musicNotation >> noteCombination;
        printNotes(noteCombination);
    }
    std::cout << std::endl;
    return 0;
}