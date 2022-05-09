#include <fstream>
#include <iostream>
#include <sstream>
#include <iterator>

struct Person {
    std::string name;
    std::string surname;
    std::string date;
    double payout;
};

std::ostream& operator << (std::ostream& out, const Person& person) {
    out << person.name << " " << person.surname << " " << person.date << " " << person.payout << std::endl;
    return out;
}

std::istream& operator >> (std::istream& in, Person& person) {
    in >> person.name >> person.surname >> person.date >> person.payout;
    return in;
}

void readPayoutConsole(const std::string& filename) {
    std::ifstream payoutStatementFile(filename, std::ios::binary);
    if (!payoutStatementFile) {
        std::cout << " Ошибка: не удалось открыть файл для чтения!" << std::endl;
        return;
    }
    std::cout.setf(std::ios::fixed);
    std::cout.precision(0);
    std::copy(std::istream_iterator<Person>(payoutStatementFile),
              std::istream_iterator<Person>(),
              std::ostream_iterator<Person>(std::cout, ""));
}

void putPayout(const std::string& filename) {
    std::ofstream payoutStatementFile(filename, std::ios::app);
    if (!payoutStatementFile) {
        std::cout << " Ошибка: не удалось открыть файл для записи!" << std::endl;
        return;
    }
    std::cout << " Выход - пустая строка." << std::endl;
    while (payoutStatementFile) {
        Person personPayoutStruct;
        std::string inputLine;
        std::cout << " Введите данные для новой записи: " << std::endl;
        std::getline(std::cin, inputLine);
        if (inputLine.empty()) break;
        std::stringstream personPayoutStream;
        personPayoutStream << inputLine;
        {
            std::string name;
            personPayoutStream >> name;
            if (std::isdigit(name[0])) {
                std::cout << " Неверное имя!" << std::endl;
                continue;
            }
            personPayoutStruct.name = name;
        }
        std::string surname;
        personPayoutStream >> surname;
        if (std::isdigit(surname[0])) {
            std::cout << " Неверная фамилия!" << std::endl;
            continue;
        }
        personPayoutStruct.surname = surname;
        try {
            std::string date;
            personPayoutStream >> date;
            int day = std::stoi(date.substr(0, 2));
            if (day < 1 || day > 31) throw -1;
            int month = std::stoi(date.substr(3, 2));
            if (month < 1 || month > 12) throw -2;
            int year = std::stoi(date.substr(6, 4));
            if (year < 1900 || year > 2021) throw -3;
            personPayoutStruct.date = date;
        } catch (int a) {
            std::cout << " Неверная дата!" << std::endl;
            continue;
        } catch (const std::exception &e) {
            std::cout << " Неверная дата!" << std::endl;
            continue;
        }
        try {
            std::string payout;
            personPayoutStream >> payout;
            personPayoutStruct.payout = std::stod(payout);
        } catch (const std::exception &e) {
            std::cout << " Неверная сумма выплаты!" << std::endl;
            continue;
        }
        payoutStatementFile.setf(std::ios::fixed);
        payoutStatementFile.precision(0);
        payoutStatementFile << personPayoutStruct;
    }
    payoutStatementFile.close();
}

int main() {
    system("chcp  65001");
    constexpr char* filename = "C:\\skillbox\\profession-c-plus-plus\\homework21.1\\payment_statement.txt";
    std::string operation;
    std::cout << " Реализация ведомости учёта." << std::endl;
    std::cout << " Введите 'list' для чтения ведомости или 'add' для записи ведомости." << std::endl;
    std::getline(std::cin, operation);
    if (operation == "list") {
        readPayoutConsole(filename);
    } else if (operation == "add") {
        putPayout(filename);
    } else {
        std::cerr << " Недопустимая команда!" << std::endl;
        return -1;
    }
    return 0;
}
