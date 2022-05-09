#include <iostream>

bool correctnessReal(std::string s) {
    bool point = false;
    int count1 = 0;
    int count2 = 0;
    if (!(s[0] >= '0' &&  s[0] <= '9') && s[0] != '-' && s[0] != '.') return false;
    if (s[0] == '.') point = true;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' &&  s[0] <= '9') count1++;
        if (s[i] == '-') count2++;
    }
    if (count1 == 0) return false;
    if (count2 > 1) return false;
    for (int i = 1; i < s.length(); i++) {
        if (!((s[i] >= '0' &&  s[0] <= '9') || (s[i] == '.' && !point))) return false;
        if (s[i] == '.') point = true;
    }
    return true;
}

std::string whole(std::string s) {
    int index;
    index = s.find('.');
    if (index < 0) {
        return s;
    } else {
        return s.substr(0, index);
    }
}

std::string fractional(std::string s) {
    int index;
    index = s.find('.');
    if (index < 0) {
        return "";
    } else {
        return s.substr(index + 1);
    }
}

std::string compareFractional(std::string f1, std::string f2) {
    int l1, l2, l;
    l1 = f1.length();
    l2 = f2.length();
    l = l1 > l2 ? l1 : l2;
    if (l1 < l2) {
        for (int i = l1; i < l; i++) {
            f1 += '0';
        }
    } else if (l1 > l2) {
        for (int i = l2; i < l; i++) {
            f2 += '0';
        }
    }
    for (int i = 0; i < l; i++) {
        if (f1[i] < f2[i]) {
            return "Less";
        } else if (f1[i] > f2[i]) {
            return "More";
        }
    }
    return "Equal";
}

std::string compare(std::string w1, std::string w2, std::string f1, std::string f2) {
    int l1, l2, l3, l4, index;
    bool positive1 = true;
    bool positive2 = true;
    if (w1[0] == '-') {
        positive1 = false;
        w1.erase(0, 1);
    }
    if (w2[0] == '-') {
        positive2 = false;
        w2.erase(0, 1);
    }
    l1 = w1.length();
    l2 = w2.length();
    for (int i = 0; i < l1; i++) {
        index = w1.find('0');
        if (index == 0) w1.erase(index, 1);
    }
    for (int i = 0; i < l2; i++) {
        index = w2.find('0');
        if (index == 0) w2.erase(index, 1);
    }
    l1 = w1.length();
    l2 = w2.length();
    l3 = f1.length();
    l4 = f2.length();
    if (l1 == 0 && l2 == 0 && l3 == 0 && l4 == 0) return "Equal";
    if (!positive1 && positive2) return "Less";
    else if (positive1 && !positive2) return "More";
    else {
        if (l1 < l2) {
            return "Less";
        } else if (l1 == l2) {
            for (int i = 0; i < l1; i++) {
                if (w1[i] < w2[i]) {
                    return "Less";
                } else if (w1[i] > w2[i]) {
                    return "More";
                }
            }
            return compareFractional(f1, f2);
        } else return "More";
    }
}


int main() {
    system("chcp 65001");
    std:: string s1, s2, w1, w2, f1, f2;
    std::cout << " Сравнение длинных вещественных чисел." << std::endl;
    std::cout << " Введите два вещественных числа: ";
    std::cin >> s1 >> s2;
    if (!(correctnessReal(s1) && correctnessReal(s2))) {
        std::cout << " Введены некорректные данные." << std::endl;
       return -1;
    }
    w1 = whole(s1);
    f1 = fractional(s1);
    w2 = whole(s2);
    f2 = fractional(s2);
    std::cout << compare(w1, w2, f1, f2) << std::endl;
    return 0;
}
