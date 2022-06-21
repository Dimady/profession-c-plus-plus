#include <iostream>
#include <vector>

class Row {
public:
    Row(std::initializer_list<int> numbers) {
        m_Row = numbers;
    }
    std::vector<int> m_Row;
};

int main() {
    Row myRow = {1, 2, 3, 4, 5};
    for (auto &i: myRow.m_Row) {
        std::cout << i << " ";
    }
}
