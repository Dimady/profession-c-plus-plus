#include <iostream>
#include <vector>
#include <iomanip>

int main() {
    system("chcp 65001");
    float sum = 0;
    std::vector<float> price {2.5, 4.25, 3.0, 10.0};
    std::vector<float> purchase {1, 1, 0, 3};
    for (int i = 0; i < price.size(); i++) {
        sum += price[purchase[i]];
    }
    std::cout << std::fixed;
    std::cout << " Суммарная стоимость покупок: " << std::setprecision(1) << sum << std::endl;
    return 0;
}
