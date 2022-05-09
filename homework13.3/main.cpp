#include <iostream>
#include <vector>

int main() {
    system("chcp 65001");
    int size = 20;
    std::vector<int> data(size);
    int curpos = 0;
    int num;
    std::cout << " Введите целые числа в базу данных." << std::endl;
    std::cin >> num;
    while (num != -2) {
        if (num == -1) {
            for (int i = curpos; i < data.size(); ++i) {
                std::cout << data[i] << " ";
            }
            for (int i = 0; i < curpos; i++) {
                std::cout << data[i] << " ";
            }
            std::cout << std::endl;
        } else {
            data[curpos] = num;
            curpos++;
            if (curpos == 20) {
                curpos = 0;
            }
        }
        std::cin >> num;
    }
    return 0;
}
