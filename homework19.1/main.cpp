#include <fstream>
#include <iostream>

int main() {
    system("chcp 65001");
    std::ifstream wordsFile("C:\\skillbox\\profession-c-plus-plus\\homework19.1\\words.txt");
    if (!wordsFile) {
        std::cout << " Ошибка: не удалось открыть файл для чтения!" << std::endl;
        return -1;
    }
    std::cout << " Введите слово для поиска: ";
    std::string searchWord;
    std::cin >> searchWord;
    int nWords = 0;
    while (wordsFile) {
        std::string word;
        wordsFile >> word;
        if (word == searchWord) ++nWords;
    }
    std::cout << " Искомое слово \"" << searchWord << "\" было найдено " << nWords
         << " раз " << std::endl;
    wordsFile.close();
    std::cout << std::endl;
    return 0;
}
