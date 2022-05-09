#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    system("chcp 65001");
    std::cout << " Введите число или -1 для отображения вектора или -2 для выхода:" << std::endl;
    std::vector<int> vec;
    int n;
    do {
        std::cin >> n;
        if (n == -1) {
                std::sort(vec.begin(), vec.end());
                std::cout << " Пятое по возрастанию число: " << vec[4] << " " << std::endl;
                continue;
        }
        vec.push_back(n);
    } while (n != -2);
}
