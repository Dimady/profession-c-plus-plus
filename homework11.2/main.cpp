#include <iostream>


bool correctnessLeft(std::string left) {
    std::string leftAlphabet;
    int l, indexLeft;
    l = left.length();
    if (left[0] == '.' || left[l - 1] == '.') return false;
    for (int i = 1; i < l - 2; i++) {
        if (left[i] == '.' && left[i + 1] == '.') return false;
    }
    if (l < 1 || l > 64) return false;
    for (char i = 'A'; i <= 'Z'; i++) leftAlphabet += i;
    for (char i = 'a'; i <= 'z'; i++) leftAlphabet += i;
    for (char i = '0'; i <= '9'; i++) leftAlphabet += i;
    leftAlphabet += "!#$%&'*+-/=?^_`{|}~.";
    for (int i = 0; i < l; i++) {
        indexLeft = leftAlphabet.find(left[i]);
        if (indexLeft < 0) return false;
    }
    return true;
}

bool correctnessRight(std::string right) {
    std::string rightAlphabet;
    int r, indexRight;
    r = right.length();
    if (right[0] == '.' || right[r - 1] == '.') return false;
    for (int i = 1; i < r - 2; i++) {
        if (right[i] == '.' && right[i + 1] == '.') return false;
    }
    if (r < 1 || r > 63) return false;
    for (char i = 'A'; i <= 'Z'; i++) rightAlphabet += i;
    for (char i = 'a'; i <= 'z'; i++) rightAlphabet += i;
    for (char i = '0'; i <= '9'; i++) rightAlphabet += i;
    rightAlphabet += "-.";
    for (int i = 0; i < r; i++) {
        indexRight = rightAlphabet.find(right[i]);
        if (indexRight < 0) return false;
    }
    return true;
}

int main() {
    system("chcp 65001");
    std::string email;
    std::string left, right;
    int index, count = 0;
    std::cout << " Проверка корректности email-адреса." << std::endl;
    std::cout << " Введите email-адрес: ";
    std::cin >> email;
    for (int i = 0; i < email.length(); i++) {
        if (email[i] == '@') count++;
    }
    if (count != 1) {
        std::cout << "No" << std::endl;
        return 0;
    } else {
        index = email.find('@');
        left = email.substr(0, index);
        right = email.substr(index + 1);
        if (correctnessLeft(left) && correctnessRight(right)) {
            std::cout << "Yes" << std::endl;
        } else std::cout << "No" << std::endl;
        return 0;
    }
}
