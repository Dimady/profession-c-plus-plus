#include <fstream>
#include <iostream>
#include <sstream>

int main() {
    system("chcp 65001");
    std::cout << std::endl;
    std::string name;
    std::string surname;
    double payment;
    std::string paymentDate;
    std::ifstream paymentStatementFile("C:\\skillbox\\profession-c-plus-plus\\homework19.3\\payment_statement.txt");
    if (!paymentStatementFile) {
        std::cout << " Ошибка: не удалось открыть файл для чтения!";
        return -1;
    }
    double sum = 0;
    double maxPayment = 0;
    while (paymentStatementFile) {
        std::string inputLine;
        std::stringstream paymentInfo;
        std::getline(paymentStatementFile, inputLine);
        paymentInfo << inputLine;
        paymentInfo >> name;
        paymentInfo >> surname;
        paymentInfo >> payment;
        paymentInfo >> paymentDate;
        if (!inputLine.empty())
            std::cout << name << "\t" << surname << " " << payment << "\t" << paymentDate << std::endl;
        sum += payment;
        if (payment > maxPayment) maxPayment = payment;
    }
    std::cout << std::endl;
    std::cout << " Итого всех выплат: " << sum << std::endl;
    std::cout << " Максимальный платеж: " << maxPayment << std::endl;
    paymentStatementFile.close();
    return 0;
}
