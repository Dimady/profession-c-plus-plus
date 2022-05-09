#include <iostream>

int main() {
    system("chcp 65001");
    std:: cout << " Банкетный стол." << std::endl;
    constexpr int n = 12;
    constexpr int m = 3;
    bool vip = false;
    int banquet[n][m] = {{3,2,1},
                         {3,2,1},
                         {3,2,1},
                         {3,2,1},
                         {3,2,1},
                         {3,2,1},
                         {3,2,1},
                         {3,2,1},
                         {3,2,1},
                         {3,2,1},
                         {4,3,1},
                         {4,3,1}};
    banquet[4][2]++;
    banquet[11][0]--;
    banquet[11][1]--;
    for (int i = 0; i < n; i++) {
        if ((i + 1) > 10) vip = true;
        std:: cout << " Персона № " << i + 1 << (vip ? " (VIP)" : "") << ": ";
        for (int j = 0; j < m; j++)
            std::cout << banquet[i][j] << " ";
        std::cout << std::endl;
    }
        return 0;
}
