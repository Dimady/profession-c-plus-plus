#include <iostream>
#include <vector>
#include <string>

std::vector <class AddressBook> list;

class AddressBook
{
public:
    std::string name;
    std::string number;
};

class Mobile
{
public:
    void add ()
    {
        AddressBook newContact;
        std::string buffer, b;
        std::cout << "Введите имя человека: ";
        std::cin >> newContact.name;
        std::cout << "Введите номер человека в формате +7<10 цифр>: ";
        std::cin >> buffer;
        b = buffer.substr(1);
        bool c = false;
        for (int i = 0; i < b.length(); i++)
            if (!isdigit(b[i])) {
                c = true;
                break;
            }
        while (buffer.size() != 12 || buffer[0] != '+' || buffer[1] != '7' || c)
        {
            std::cout << "Неверный номер! Повторите ввод." << std::endl;
            std::cout << "Введите номер человека в формате +7<10 цифр>: ";
            std::cin >> buffer;
        }
        newContact.number = buffer;
        list.push_back(newContact);
    };

    void call()
    {
        std::string buffer;
        std::cout << "Кому вы хотите позвонить? ";
        std::cin >> buffer;
        for (int i = 0; i < list.size(); i++)
        {
            if(buffer == list[i].name)
            {
                std::cout << "Мы звоним " << list[i].name << " по номеру: " << list[i].number << std::endl;
            } else if (buffer == list[i].number)
            {
                std::cout << "Мы звоним " << list[i].name << " по номеру: " << list[i].number << std::endl;
            } else std::cout << "Такой человек в телефонной книге не найден." << std::endl;
        }
    };
    void sms()
    {
        std::string buffer;
        std::string message;
        std::cout << "введите сообщение: ";
        std::cin >> std::ws;
        std::getline (std::cin, message);
        std::cout << "Кому вы хотите его отправить? ";
        std::cin >> buffer;
        for (int i = 0; i < list.size(); i++)
        {
            if(buffer == list[i].name)
            {
                std::cout << "SMS " << message <<" было отправлено " << list[i].name << " по номеру: " << list[i].number << std::endl;
            } else if (buffer == list[i].number)
            {
                std::cout << "SMS " << message <<" было отправлено " << list[i].name << " по номеру: " << list[i].number << std::endl;
            } else std::cout << "Такой человек в телефонной книге не найден." << std::endl;
        }
    };
};

int main() {
    system("chcp 65001");
    std::cout << "Реализация программы симуляции мобильного телефона." << std:: endl;
    std::cout << std:: endl;
    Mobile myMobile;
    std::string command;
    std::cout << "Список доступных команд:" << std:: endl;
    std::cout << "add" << std::endl;
    std::cout << "call" << std::endl;
    std::cout << "sms" << std::endl;
    std::cout << "exit" << std::endl;
    std::cout << std::endl;
    std::cout << "Введите команду: ";
    std::cin >> command;
    while (command != "exit") {
        if (command == "add") myMobile.add();
        else if (command == "call") myMobile.call();
        else if (command == "sms") myMobile.sms();
        else std::cout << "Неверная команда! Повторите ввод." << std::endl;
        std::cout << "Введите команду: ";
        std::cin >> command;
    }
    return 0;
}