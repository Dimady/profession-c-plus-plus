#include <iostream>
#include <map>
#include <string>

/* тут мы будем создавать map в котором будут буквы от слова и их количество
   в качестве ключа будет буква, в качестве значения - сколько раз она встречается в слове
   перебираем буквы в слове
   увидели букву, записали букву в качестве ключа, и в качестве значения добавили единичку...
   если буква еще раз встретится, то еще раз добавится единичка
   вернем наш список букв и их количества */

std::map<char, int> stringToMap(const std::string &s) {
    std::map <char, int> c;
    for (char ch: s) ++c[ch];
    return c;
}

int main() {
    system("chcp 65001");
    std::cout << " Анаграммы." << std::endl;
    std::string a, b;
    std::cout << " Введите первое слово: ";
    std::cin >> a;
    std::cout << " Введите первое слово: ";
    std::cin >> b;
    if(a.length() != b.length()) std::cout << "false";
    else if (stringToMap(a) == stringToMap(b)) {
        std::cout << "true";
    } else std::cout << "false";
    std::cout << std::endl;
    return 0;
}