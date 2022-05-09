#include <iostream>
#include <vector>

int main()
{
    system("chcp 65001");
    std::vector<int> vec {2, 7, 11, 15}; // вектор
    int sum = 9; // необходимая сумма
    int lt = 0;
    int rt = vec.size() - 1;
    while (lt != rt)
    {
        int cursum = vec[lt] + vec[rt];
        if (cursum < sum) {
            lt++;
        } else if (cursum > sum) {
            rt--;
        } else {
            std::cout << " Значения: " << vec[lt] << " " << vec[rt] << std::endl;
            return 0;
        }
    }
    std::cout << " Не найдено" << std::endl;
    return 0;
}
