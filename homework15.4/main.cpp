#include <iostream>
#include <vector>

int main()
{
    std::vector<int> vec = {-100, -50, -5, 1, 10, 15};
    int i = 0;
    while (vec[i] < 0) i++;
    std::cout << vec[i] << " ";
    for(int j = 0; j < i; j++) {
        if ((i - 1 - j) < 0) std::cout << vec[i + 1 + j] << " ";
        else if ((i + 1 + j) > (vec.size() - 1)) std::cout << vec[i - 1 - j] << " ";
        else {
            if (abs(vec[i - 1 - j]) <= vec[i + 1 + j]) std::cout << vec[i - 1 - j] << " " << vec[i + 1 + j] << " ";
            else std::cout << vec[i + 1 + j] << " " << vec[i - 1 - j] << " ";
        }
    }
    return 0;
}
