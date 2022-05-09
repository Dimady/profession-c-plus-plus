#include <iostream>
#include <map>
#include <string>

int main() {
    system("chcp 65001");
    std::cout << " Регистратура." << std::endl;
    std::cout << " Exit - выход." << std::endl;
    std::cout << " Next - вызов человека в регистратуру." << std::endl;
    std::map<std::string, int> queue;
    std::string str;
    do {
        std::cout << " Введите фамилию:";
        std::cin >> str;
        if (str == "Next") {
            while (!queue.empty()) {
                if (std::map<std::string, int>::iterator begin = queue.begin(); begin->second == 0) {
                    queue.erase(begin);
                    if (queue.empty()) {
                        std::cout << " Очередь пуста." << std::endl;
                        return 0;
                    }
                }
                else {
                    std::cout << begin->first << std::endl;
                    --begin->second;
                    break;
                }
            }
        } else ++queue[str];
    } while (str != "Exit");
    return 0;
}