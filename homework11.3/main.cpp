#include <iostream>

bool correctnessIP(std::string ip) {
    std::string ipAlphabet;
    int l, index;
    l = ip.length();
    if (l > 3) return false;
    if (ip[0] == '0' && l > 1) return false;
    for (char i = '0'; i <= '9'; i++) ipAlphabet += i;
    for (int i = 0; i < l; i++) {
        index = ipAlphabet.find(ip[i]);
        if (index < 0) return false;
    }
    if (std::stoi(ip) > 255) return false;
    return true;
}

int main() {
    system("chcp 65001");
    std::string ip, ip1, ip2, ip3, ip4;
    int l, index, count = 0;
    std::cout << " Валидация IP-адреса." << std::endl;
    std::cout << " Введите IP-адрес: ";
    std::cin >> ip;
    l = ip.length();
    for (int i = 0; i < l; i++) {
        if (ip[i] == '.') count++;
    }
    for (int i = 0; i < l - 1; i++) {
        if ((ip[i] == '.') && (ip[i + 1] == '.')) {
            std::cout << "No" << std::endl;
            return 0;
        }
    }
    if (count != 3) {
        std::cout << "No" << std::endl;
        return 0;
    } else {
        index = ip.find('.');
        ip1 = ip.substr(0, index);
        ip = ip.substr(index + 1);
        index = ip.find('.');
        ip2 = ip.substr(0, index);
        ip = ip.substr(index + 1);
        index = ip.find('.');
        ip3 = ip.substr(0, index);
        ip4 = ip.substr(index + 1);
        if (correctnessIP(ip1) && correctnessIP(ip2) &&
            correctnessIP(ip3) && correctnessIP(ip4)) {
            std::cout << "Yes" << std::endl;
        } else std::cout << "No" << std::endl;
    }
    return 0;
}
