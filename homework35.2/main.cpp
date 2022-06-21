#include <iostream>
#include <memory>
#include <vector>
#include <unordered_set>

int main() {
    std::vector<int> vec = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5};
    auto test = [] (std::vector<int> p) {
        std::unordered_set<int> temp;
        std::vector<int> newP;
        for (int i: p) {
            temp.insert(i);
        }
        newP.insert(newP.begin(),temp.begin(), temp.end());
        return std::make_unique<std::vector<int>>(newP);
    };
    auto res = test(vec);
    for (auto i: *res) {
        std::cout << i << " ";
    }
}