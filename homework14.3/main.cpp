#include <iostream>

constexpr int n = 5;
int a[n][n];

void rows_by_snake() {
    int i, j, k = 0;
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++) {
            a[i][j] = (i % 2 ? (i + 1) * n - j - 1 : k);
            k++;
        }
}

void output_matrix() {
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }
}

int main () {
    system("chcp 65001");
    std:: cout << " Проход змейкой." << std::endl;
    rows_by_snake();
    output_matrix();
    return 0;
}