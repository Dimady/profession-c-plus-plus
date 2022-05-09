#include <iostream>
#include <vector>

int main() {
    system("chcp 65001");
    int n, x;
    std::cout << "n = ";
    std::cin >> n;
    std::vector<int> vec(n);
    std::vector<int> temp(n);
    for (int i = 0; i < vec.size(); i++) {
        std::cout << i + 1 << ": ";
        std::cin >> vec[i];
    }
    std::cout << " Какие значения из вектора удалить? ";
    std::cin >> x;
    int j = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (x != vec[i]) {
            temp[j] = vec[i];
            j++;
        }
    }
    vec.resize(j);
    temp.resize(j);
    vec = temp;
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}

