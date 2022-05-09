#include <iostream>

int main() {
    system("chcp 65001");
    constexpr int n = 4;
    float a[n][n], b[n], c[n] = {0, 0, 0, 0};
    std::cout << " Умножение матрицы на вектор." << std::endl;
    std::cout << " Введите вещественные значения в матрицу (4x4):" << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) std::cin >> a[i][j];
    std::cout << " Введите вектор (размер 4):" << std::endl;
    for (int i = 0; i < n; i++) std::cin >> b[i];
    std::cout << " Результат умножения матрицы на вектор:" << std::endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) c[i] += a[i][j] * b[i];
    for (int i = 0; i < n; i++) std::cout << c[i] << " ";
    std::cout << std::endl;
    return 0;
}
