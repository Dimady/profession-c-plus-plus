#include <iostream>

constexpr int n = 10;
constexpr int m = 4;
bool field1[n][n];
bool field2[n][n];

bool isLoser(bool field[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (field[i][j]) {
                return false;
            }
    return true;
}

void initMap(bool field[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            field[i][j] = false;
}

void printMap(bool field[n][n]) {
    std::cout << "  ";
    for (int i = 0; i < n; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < n; i++) {
        std::cout << i << " ";
        for (int j = 0; j < n; j++) {
            if (field[i][j]) {
                std::cout << 'O' << " ";
            } else {
                std::cout << '.' << " ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

bool isCellValid(int x, int y) {
    if (x < 0 || x >= n || y < 0 || y >= n) {
        std::cout << " Координаты вне диапазона!" << std::endl;
        std::cout << std::endl;
        return false;
    }
    return true;
}

bool freeCells(bool field[n][n], int i, int x, int y) {
    for (int j = 0; j <= i; j++) {
        if (((y + j > n - 1) || field[y + j][x]) && ((x + j > n - 1) || field[y][x + j])) {
            std::cout << " На эти координаты нельзя поставить корабль размерностью " << (i + 1) << "!" << std::endl;
            return false;
        }
    }
    return true;
};

bool isShip(bool field[n][n], int i, int x1, int y1, int x2, int y2) {
    bool a = (x2 - x1) == i;
    bool b = (y2 - y1) == i;
    if ((a || b) && !(a && b)) {
        for (int i = y1; i <= y2; i++)
            for (int j = x1; j <= x2; j++)
                if (field[i][j]) {
                    std::cout << " Введены неверные координаты конца корабля. Повторите ввод." << std::endl;
                    return false;
                }
        return true;
    } else {
        std::cout << " Введены неверные координаты конца корабля. Повторите ввод." << std::endl;
        return false;
    }
}

void creationShips(bool field[n][n]) {
    int x1, y1, x2, y2;
    std::cout << " Игрок расставляет свои корабли." << std::endl;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j <= m - i; j++) {
            std::cout << " " <<  j << " корабль размерностью " << (i + 1) << ":" << std::endl;
            do {
                std::cout << " Введите координаты" << ((i != 0) ? " начала" : "") << " корабля (x и y): " << std::endl;
                std::cin >> x1 >> y1;
            } while (!(freeCells(field, i, x1, y1)) || !isCellValid(x1, y1));
            if (i == 0) {
                field[y1][x1] = true;
                printMap(field);
                continue;
            }
            do {
                std::cout << " Введите координаты конца корабля (x и y): " << std::endl;
                std::cin >> x2 >> y2;
            } while (!isCellValid(x2, y2) || !isShip(field, i, x1, y1, x2, y2));
            for (int i = y1; i <= y2; i++)
                for (int j = x1; j <= x2; j++)
                    field[i][j] = true;
            printMap(field);
        }
    }
}

void shot(bool field[n][n]) {
    int x, y;
    do {
        std::cout << " Введите координаты (x и y): " << std::endl;
        std::cin >> x >> y;
    } while (!isCellValid(x, y));
    if (field[y][x]) {
        std::cout << "  Цель поражена! " << std::endl;
        field[y][x] = false;
        std::cout << "  Поле атакуемого игрока:" << std::endl;
        printMap(field);
    } else {
        std::cout << "  Мимо! " << std::endl;
    }
}

int main() {
    system("chcp 65001");
    std::cout << "  Морской бой." << std::endl;
    std::cout << std::endl;
    std::cout << "  Поле игрока № 1:" << std::endl;
    initMap(field1);
    printMap(field1);
    creationShips(field1);
    std::cout << "  Поле игрока № 2:" << std::endl;
    initMap(field2);
    printMap(field2);
    creationShips(field2);
    while (true) {
        std::cout << " Стреляет игрок № 1:" << std::endl;
        shot(field2);
        if (isLoser(field2)) {
            std::cout << " Победил игрок № 1! " << std::endl;
            return 0;
        }
        std::cout << " Стреляет игрок № 2:" << std::endl;
        shot(field1);
        if (isLoser(field1)) {
            std::cout << " Победил игрок № 2! " << std::endl;
            return 0;
        }
    }
}

