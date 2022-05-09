//Алгоритм Джея Кадане
#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int ans = vec[0];
    int ans_l = 0, ans_r = 0, sum = 0, minus_pos = -1;
    for (int r = 0; r < vec.size(); ++r) {
        sum += vec[r];
        if (sum > ans) {
            ans = sum;
            ans_l = minus_pos + 1;
            ans_r = r;
        }
        if (sum < 0) {
            sum = 0;
            minus_pos = r;
        }
    }
    std::cout << ans_l << " " << ans_r << std::endl;
    return 0;
}