#include <iostream>

constexpr int n = 4;
int a[n][n], b[n][n];

bool equal() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (a[i][j] != b[i][j]) return false;
        return true;
}

int main() {
    system("chcp 65001");
    std::cout << " Равенство матриц." << std::endl;
    std::cout << " Введите значения в первую матрицу (4x4):" << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> a[i][j];
    std::cout << " Введите значения во вторую матрицу (4x4):" << std::endl;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) std::cin >> b[i][j];
            if (equal()) {
                std::cout << " Матрицы равны." << std::endl;
            } else {
                std::cout << " Матрицы не равны." << std::endl;
            }
    return 0;
}
