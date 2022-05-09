#include <iostream>
#include <vector>

constexpr int n = 4;

void swapvec(std::vector <int>& a, int* b)
{
    int temp;
    for (int i = 0; i < n; i++) {
        temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}

int main()
{
    std::vector <int> a = {1, 2, 3, 4};
    int b[] = {2, 4, 6, 8};
    swapvec(a, b);
    for (int i: a) std::cout << i << " ";
    std::cout << std::endl;
    for (int i: b) std::cout << i << " ";
    return 0;
}
