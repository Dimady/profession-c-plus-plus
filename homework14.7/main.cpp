#include <iostream>

constexpr int n = 12;
bool pimple[n][n];
int count;

void initMap() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) pimple[i][j] = true;
}

void printMap() {
    count = 0;
    for (int i = 0; i <= n; i++) {
        if (i > 0 && i < 10) std::cout << " ";
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << i + 1 << " ";
        if (i < 9) std::cout << " ";
        for (int j = 0; j < n; j++) {
            if (pimple[i][j]) {
                std::cout << 'O' << "  ";
            } else {
                std::cout << 'X' << "  ";
                count++;
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isCellValid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        std::cout << " Координаты вне диапазона." << std::endl;
        std::cout << std::endl;
        return false;
    }
        return true;
}

bool isRectangle(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) {
        std::cout << " Введены неверные координаты конца прямоугольного региона." << std::endl;
        std::cout << std::endl;
        return false;
    }
    return true;
}

int main() {
    system("chcp 65001");
    int x1, x2, y1, y2;
    std::cout << " Пупырка." << std::endl;
    std::cout << std::endl;
    initMap();
    printMap();
    do {
        do {
            std::cout << " Введите координаты x и y начала прямоугольного региона: " << std::endl;
            std::cin >> x1 >> y1;
            x1--;
            y1--;
        } while (!isCellValid(x1, y1));
        do {
            std::cout << " Введите координаты x и y конца прямоугольного региона: " << std::endl;
            std::cin >> x2 >> y2;
            x2--;
            y2--;
        } while (!isCellValid(x2, y2) || (!isRectangle(x1, y1, x2, y2)));
        for (int i = x1; i <= x2; i++)
            for (int j = y1; j <= y2; j++)
                if (pimple[i][j]) {
                pimple[i][j] = false;
                std::cout << " Pop!" << std::endl;
            }
        printMap();
    } while (count != n * n);
    return 0;
}
