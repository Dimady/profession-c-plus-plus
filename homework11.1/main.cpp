#include <iostream>

std::string codeEncode(std::string text, int k) {
    std::string alphabet1, alphabet2;
    char c;
    int index;
    for (char i = 'A'; i <= 'Z'; i++) alphabet1 += i;
    for (char i = 'a'; i <= 'z'; i++) alphabet2 += i;
    int letterQty = alphabet1.length();
    k %= letterQty;
    std::string retVal = "";
    for (int i = 0; i < text.length(); i++)
    {
        c = text[i];
        index = alphabet1.find(c);
        if (index < 0) {
            index = alphabet2.find(c);
            if (index < 0) {
                //если символ не найден, то добавляем его в неизменном виде
                retVal += c;
            } else {
                int codeIndex = (letterQty + index + k) % letterQty;
                retVal += alphabet2[codeIndex];
            }
        } else {
            int codeIndex = (letterQty + index + k) % letterQty;
            retVal += alphabet1[codeIndex];
        }
    }
    return retVal;
}

//шифрование текста
std::string encrypt_caesar(std::string plainMessage, int key) {
    return codeEncode(plainMessage, key);
}

//дешифрование текста
std::string decrypt_caesar(std::string encryptedMessage, int key) {
    return codeEncode(encryptedMessage, -key);
}

int main() {
    system("chcp 65001");
    std::string s, c;
    int key;
    std::cout << " Реализация шифра Цезаря." << std::endl;
    std::cout << " Введите текст: ";
    std::getline(std::cin, s);
    std::cout << " Введите ключ: ";
    std::cin >> key;
    c = encrypt_caesar(s, key);
    std::cout << " Зашифрованное сообщение: " << c << std::endl;
    std::cout << " Расшифрованное сообщение: "<< decrypt_caesar(c, key) << std::endl;
    return 0;
}

