#include <iostream>
#include <fstream>
#include <ctime>

constexpr char* filename = "C:\\skillbox\\profession-c-plus-plus\\homework20.4\\bank.bin";

int main() {
    system("chcp 65001");
    std::srand(time(nullptr));
    int bills[5] = {100, 200, 500, 1000, 5000};
    int money[1000];
    std::string operation;
    long sum = 0;
    std::cout << " Реализация симуляции банкомата." << std::endl;
    std::ifstream in(filename, std::ios::binary);
    if (in.is_open()) {
        in.read((char*) money, sizeof(money));
        in.close();
    } else {
        for (int i = 0; i < 1000; ++i) money[i] = 0;
    }
    for (int i = 0; i < 1000; ++i)  sum += money[i];
    std::cout << " Общая сумма денег в банкомате: " << sum << " рублей." << std::endl;
    std::cout << " Введите '+' для внесения наличных или '-' для снятия денег." << std::endl;
    std::cin >> operation;
    if (operation == "+") {
        int deposit = 0;
        for (int i = 0; i < 1000; ++i)
            if (money[i] == 0) {
                money[i] = bills[std::rand() % 5];
                deposit += money[i];
            }
        if (deposit > 0) {
            std::cout << " Сумма, внесенная в банкомат: " << deposit << " рублей." << std::endl;
            std::ofstream out(filename, std::ios::binary);
            out.write((char*) money, sizeof(money));
            return 0;
        } else {
            std::cout << " Внесение денег в банкомат не требуется." << std::endl;
            return 0;
        }
    } else if (operation == "-") {
        std::cout << " Введите необходимую сумму:";
        int amount;
        std::cin >> amount;
        if (amount % 100 != 0) {
            std::cerr << " Неверная сумма!" << std::endl;
            return -1;
        }
        int amount_to_collect = amount;
        for (int i = 4; i >= 0; --i) {
            int bill = bills[i];
            for (int j = 0; j < 1000; ++j) {
                if (money[j] == bill) {
                    if (amount_to_collect >= bill) {
                        money[j] = 0;
                        amount_to_collect -= bill;
                        if (amount_to_collect == 0) {
                            std::cout << " Взятая сумма: " << amount << std::endl;
                            std::ofstream out(filename, std::ios::binary);
                            out.write((char*) money, sizeof(money));
                            return 0;
                        }
                    }
                }
            }
        }
        std::cerr << " Нет подходящих банкнот в банкомате!" << std::endl;
        return -1;
    } else {
        std::cerr << " Неизвестная операция!" << std::endl;
        return -1;
    }
}
