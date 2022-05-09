#include <fstream>
#include <iostream>

int main() {
    system("chcp  65001");
    std::cout << " Реализация симуляции игры «Рыбалка»." << std::endl;
    std::ifstream river("C:\\skillbox\\profession-c-plus-plus\\homework20.3\\river.txt");
    std::ofstream basket("C:\\skillbox\\profession-c-plus-plus\\homework20.3\\basket.txt", std::ios::app);
    if (!river || !basket) {
        std::cout << " Ошибка: не удалось открыть файл!" << std::endl;
        return -1;
    }
    std::cout << " Введите название рыбы, которую хотите поймать: ";
    std::string fishToCatch;
    std::cin >> fishToCatch;
    int nFishes = 0;
    while (river) {
        std::string fishInRiver;
        river >> fishInRiver;
        if (fishToCatch == fishInRiver) {
            basket << fishInRiver << std::endl;
            ++nFishes;
        }
    }
    if (nFishes != 0)
        std::cout << " Вы поймали: " << nFishes << " шт. рыбы " << fishToCatch;
    else
        std::cout << " Вы ничего не поймали!";
    river.close();
    basket.close();
    std::cout << std::endl;
    return 0;
}
