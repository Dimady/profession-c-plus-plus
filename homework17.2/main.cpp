#include <iostream>

constexpr int n = 10;
int a[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

void reverse(int* a) {
    int j = n - 1;
    int temp;
    for (int i = 0; i < n / 2; i++) {
        temp = *(a + i);
        *(a + i) = *(a + j);
        *(a + j) = temp;
        j--;
    }
}

int main() {
    std::cout << std::endl;
    reverse(a);
    for(int i = 0; i < n; ++i)
        std::cout << a[i] << " ";
    return 0;
}