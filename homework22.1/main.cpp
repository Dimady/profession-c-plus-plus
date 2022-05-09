#include <iostream>
#include <string>
#include <vector>
#include <map>

enum Request {
    ADD,
    FIND_LAST_NAME,
    FIND_PHONE,
    ERROR,
    EXIT
};

std::pair<std::string, std::string> parseNumberToSurname(const std::string &answer) {
    return (std::make_pair(answer.substr(0, 8), answer.substr(9, answer.size() - 1)));
}

std::pair<std::string, std::vector<std::string>> parseSurnameToNumber(const std::string &answer, std::vector<std::string> &vec) {
    vec.push_back(answer.substr(0, 8));
    return (std::make_pair(answer.substr(9, answer.size() - 1), vec));
}

std::string parsePhone(const std::string &answer) {
    if (answer.size() < 8) {
        std::cout << " Номер телефона не может содержать менее 8 символов!" << std::endl;
    } else if (answer[2] != '-' || answer[5] != '-' || answer.size() > 8) {
        std::cout << " Неверный формат телефона. Должен быть: XX-XX-XX." << std::endl;
    } else {
        return answer;
    }
    return "Error";
}

Request request(const std::string &req) {
    if (req.empty()) {
        return EXIT;
    } else if (isalpha(req[0])) {
        return FIND_PHONE;
    } else if (isdigit(req[0])) {
        if (req.size() >= 10 && req[8] == ' ') {
            return ADD;
        } else {
            return FIND_LAST_NAME;
        }
    }
    return ERROR;
}

int main() {
    system("chcp 65001");
    std::pair<std::string, std::string> data1;
    std::pair<std::string, std::vector<std::string>> data2;
    std::map<std::string, std::string>::iterator it1;
    std::map<std::string, std::vector<std::string>>::iterator it2;
    std::map<std::string, std::string> numberToSurname;
    std::map<std::string, std::vector<std::string>> surnameToNumber;
    std::vector<std::string> vec;
    std::cout << " Телефонный справочник." << std::endl;
    std::cout << " Выход - пустая строка." << std::endl;
    while (true) {
        std::cout << " Введите запрос: ";
        std::string answer, pars_phone;
        bool exit = false;
        std::getline(std::cin, answer);
        switch (request(answer)) {
            case ADD:
                data1 = parseNumberToSurname(answer);
                it1 = numberToSurname.find(answer.substr(0, 8));
                if (data1.first == it1->first) {
                    std::cout << " Телефон уже существует";
                    std::cout << " со значением: " << data1.second << std::endl;
                    break;
                }
                numberToSurname.insert(data1);
                data2 = parseSurnameToNumber(answer, vec);
                surnameToNumber.insert(data2);
                std::cout << " Добавлена запись: " << answer << std::endl;
                break;
            case FIND_LAST_NAME:
                pars_phone = parsePhone(answer);
                if (pars_phone == "Error") break;
                it1 = numberToSurname.find(pars_phone);
                if (it1 == numberToSurname.end()) {
                    std::cout << " Телефон не найден!" << std::endl;
                } else {
                    std::cout << it1->second << std::endl;
                }
                break;
            case FIND_PHONE:
                it2 = surnameToNumber.find(answer);
                if (it2 == surnameToNumber.end()) {
                    std::cout << " Фамилия не найдена!" << std::endl;
                } else {
                    for (int i = 0; i < data2.second.size(); ++i)
                        std::cout << data2.second[i] << " ";
                    std::cout << std::endl;
                    }
                    break;
            case ERROR:
                std::cout << " Некорректный ввод данных!" << std::endl;
                break;
            case EXIT:
                exit = true;
                break;
        }
        if (exit) break;
    }
    return 0;
}
