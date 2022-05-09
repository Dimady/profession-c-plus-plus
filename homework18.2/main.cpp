#include <iostream>

int rabbitStep(int n) {
    if (n == 0) return 1;
    int countSteps = 0;
    for (int i = 1; i <= std::min(n, 3); ++i) countSteps += rabbitStep(n - i);
    return countSteps;
}

int main()
{
    system("chcp 65001");
    int n;
    std::cout << " Введите количество ступеней лестницы: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << " Некорректный ввод данных. " << std::endl;
        return -1;
    }
    std::cout << " Количество способов, которыми кролик может доскакать до " << n << "-й ступеньки: ";
    std::cout << rabbitStep(n) << std::endl;
    return 0;
}