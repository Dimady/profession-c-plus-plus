#include <iostream>

int rabbitStep(int n, int k = 3) {
    if (n == 0) return 1;
    int countSteps = 0;
    for (int i = 1; i <= std::min(n, k); ++i) countSteps += rabbitStep(n - i, k);
    return countSteps;
}

int main()
{
    system("chcp 65001");
    int n, max_jump;
    std::cout << " Введите количество ступеней лестницы: ";
    std::cin >> n;
    if (n <= 0) {
        std::cout << " Некорректный ввод данных. " << std::endl;
        return -1;
    }
    std::cout << " Количество способов, которыми кролик может доскакать до " << n << "-й ступеньки: ";
    std::cout << rabbitStep(n) << std::endl;
    std::cout << " Введите максимальную длину прыжка: ";
    std::cin >> max_jump;
    if (max_jump <= 0) {
        std::cout << " Некорректный ввод данных. " << std::endl;
        return -1;
    }
    std::cout << " Количество способов, которыми кролик может доскакать до " << n << "-й ступеньки: ";
    std::cout << rabbitStep(n, max_jump) << std::endl;
    return 0;
}
