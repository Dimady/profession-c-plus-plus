#include <iostream>

void even_digits(long long& n, int& a)
{
    if ((n & 1) == 0) ++a;
    if (n / 10 == 0) return;
    n /= 10;
    even_digits(n, a);
}

int main() {
    system("chcp 65001");
    std::cout << " Рекурсивный счет четных цифр." << std::endl;
    long long n = 9223372036854775806;
    int ans = 0;
    std::cout << " n = " << n << std::endl;
    even_digits(n, ans);
    std::cout << " Количество четных цифр: " << ans << std::endl;
    return 0;
}
