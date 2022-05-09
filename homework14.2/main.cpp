#include <iostream>

constexpr char DOT_EMPTY = ' ';
constexpr char DOT_X = 'X';
constexpr char DOT_O = 'O';
constexpr int size = 3;  // Размер поля
char map[size][size];

/** Проверяем горизонтальные и вертикальные линии */
bool checkLines(char symb, int offsetX, int offsetY) {
    bool cols, rows;
    for (int col = offsetX; col < 3 + offsetX; col++) {
        cols = true;
        rows = true;
        for (int row = offsetY; row < 3 + offsetY; row++) {
            cols &= (map[col][row] == symb);
            rows &= (map[row][col] == symb);
        }

        if (cols || rows) return true;
    }
    return false;
}

bool checkWin(char symb) {
        for (int col = 0; col < size - 2; col++) {
            for (int row = 0; row < size - 2; row++) {
                if (checkLines(symb, col, row)) return true;
            }
        }
        return false;
    }

bool isMapFull() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (map[i][j] == DOT_EMPTY) return false;
        }
    }
    return true;
}

bool isCellValid(int x, int y) {
    if (x < 0 || x >= size || y < 0 || y >= size) {
        std::cout << " Введены неверные координаты." << std::endl;
        std::cout << std::endl;
        return false;
    }
    if (map[y][x] == DOT_EMPTY) {
        return true;
    } else {
        std::cout << " Эта клетка занята." << std::endl;
        std::cout << std::endl;
        return false;
    }
}

void petyaTurn() {
        int x, y;
        do {
            std::cout << " Ход Пети." << std::endl;
            std::cout << " Введите координаты X и Y: ";
            std::cin >> x >> y;
            x--;
            y--;
        } while (!isCellValid(x, y));
        map[y][x] = DOT_X;
    }

void vanyaTurn() {
    int x, y;
    do {
        std::cout << " Ход Вани." << std::endl;
        std::cout << " Введите координаты X и Y: ";
        std::cin >> x >> y;
        x--;
        y--;
    } while (!isCellValid(x, y));
    map[y][x] = DOT_O;
}

void initMap() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            map[i][j] = DOT_EMPTY;
        }
    }
}

void printMap() {
    for (int i = 0; i <= size; i++) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < size; j++) {
            std::cout << map[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int main() {
    system("chcp 65001");
    std::cout << " Крестики-нолики." << std::endl;
    initMap();
    printMap();
    while (true) {
        petyaTurn();
        printMap();
        if (checkWin(DOT_X)) {
            std::cout << " Петя победил!" << std::endl;
            break;
        }
        if (isMapFull()) {
            std::cout << " Ничья." << std::endl;
            break;
        }
        vanyaTurn();
        printMap();
        if (checkWin(DOT_O)) {
            std::cout << " Ваня победил!" << std::endl;
            break;
        }
        if (isMapFull()) {
            std::cout << " Ничья." << std::endl;
            break;
        }
    }
    std::cout << " Игра окончена." << std::endl;
    return 0;
}
