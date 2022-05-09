#include <iostream>

int main() {
    system("chcp 65001");
    constexpr int n = 5;
    constexpr int m = 10;
    bool block[n][n][m];
    int h, cut;
    std::cout << " Почти-Майнкрафт." << std::endl;
    std::cout << " Введите высоту блоков (0-9):" << std::endl;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << (i * n + j + 1) << ": ";
            std::cin >> h;
            if (h < 0 || h > 9) {
                std::cout << " Введены некорректные данные. Повторите ввод." << std::endl;
                j--;
                }
            else {
                for(int k = 0; k <= h; k++) block[i][j][k] = true;
                for(int k = h + 1; k < m; k++) block[i][j][k] = false;
            }
        }
    }
    do {
        std::cout << " Введите высоту среза (0-9):" << std::endl;
        std::cin >> cut;
    } while (cut < 0 || cut > 9);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << block[i][j][cut] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
