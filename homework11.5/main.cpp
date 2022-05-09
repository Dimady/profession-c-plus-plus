#include <iostream>

constexpr int size = 3;  // Размер поля
std::string map[size];

bool correctnessString(std::string s) {
    std::string gameAlphabet = "XO.";
    int l, index;
    l = s.length();
    if (l != size) return false;
    for (int i = 0; i < l; i++) {
        index = gameAlphabet.find(s[i]);
        if (index < 0) return false;
    }
    return true;
}

int countChar(char c) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) if (map[i][j] == c) count++;
    }
    return count;
}

/** Проверяем диагонали */
bool checkDiagonal(char symb, int offsetX, int offsetY) {
    bool toright, toleft;
    toright = true;
    toleft = true;
    for (int i = 0; i < size; i++) {
        toright &= (map[i + offsetX][i + offsetY] == symb);
        toleft &= (map[size - 1 - i + offsetX][i + offsetY] == symb);
    }
    if (toright || toleft) return true;
    return false;
}

/** Проверяем горизонтальные и вертикальные линии */
bool checkLines(char symb, int offsetX, int offsetY) {
    bool cols, rows;
    for (int col = offsetX; col < size + offsetX; col++) {
        cols = true;
        rows = true;
        for (int row = offsetY; row < size + offsetY; row++) {
            cols &= (map[col][row] == symb);
            rows &= (map[row][col] == symb);
        }
        if (cols || rows) return true;
    }
    return false;
}

    /** Логика победы */
    bool checkWin(char symb) {
        for (int col = 0; col < size - 2; col++) {
            for (int row = 0; row < size - 2; row++) {
                if (checkDiagonal(symb, col, row) || checkLines(symb, col, row)) return true;
            }
        }
        return false;
    }

int main() {
    system("chcp 65001");
    std::cout << " Анализ результатов игры в крестики-нолики." << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << " Введите " << i + 1 << " строку: ";
        std::cin >> map[i];
        if (!(correctnessString(map[i]))) {
            std::cout << "Incorrect" << std::endl;
            return 0;
        }
    }
    if (checkWin('X')) {
        if (countChar('X') - countChar('O') == 1) {
            std::cout << "Petya won!" << std::endl;
        } else std::cout << "Incorrect" << std::endl;
    } else if (checkWin('O')) {
        if (countChar('O') == countChar('X')) {
            std::cout << "Vanya won!" << std::endl;
        } else std::cout << "Incorrect" << std::endl;
    } else {
        std::cout << "Nobody" << std::endl;
    }
    return 0;
}



