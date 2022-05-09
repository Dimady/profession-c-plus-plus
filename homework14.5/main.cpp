#include <iostream>

int main() {
    system("chcp 65001");
    constexpr int n = 4;
    float m[n][n];
    std::cout << " Диагональная матрица." << std::endl;
    std::cout << " Введите вещественные значения в матрицу (4x4):" << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> m[i][j];
    for(int i=0; i < n; i++)
        for(int j = 0; j < n; j++)
            if((i != j) && (j != (n-1) - i)) m[i][j] = 0;
    std::cout << " Диагональная матрица:" << std::endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) std::cout << m[i][j] << " ";
            std::cout << std::endl;
            }
    return 0;
}
