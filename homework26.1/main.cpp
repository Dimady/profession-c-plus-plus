#include <iostream>
#include <ctime>
#include <vector>

constexpr int n = 3;

class Track {
public:
    std::string name;
    std::string date;
    int duration;
};

class Player {
public:
    bool parametr = 0;

    Track tracks[n] = {{"one", "29/11/2012", 100},
                       {"two", "01/01/2013", 360},
                       {"three", "15/06/2016", 240}};

    void play() {
        if (parametr) return;
        else {
            std::cout << "Введите имя трека: ";
            std::string name;
            std::cin >> name;
            bool find = 0;
            for (int i = 0; i < n; ++i) {
                if (name == tracks[i].name) {
                    std::cout << "Имя: " << tracks[i].name << " Дата: " << tracks[i].date << " Продолжительность: " << tracks[i].duration << std::endl;
                    find = 1;
                    break;
                }
            }
            if (!find) {
                std::cout << "Трек " << name << " не найден!" << std::endl;
                return;
            }
            parametr = 1;
        }
    }

    void pause() {
        if (!parametr) return;
        std::cout << "Трек поставлен на паузу." << std::endl;
        parametr = 0;
    }

    void next() {
        srand(time(0));
        int i = rand() % 3;
        std::cout << "Имя: " << tracks[i].name << " Дата: " << tracks[i].date << " Продолжительность: " << tracks[i].duration << std::endl;
        parametr = 1;
    }

    void stop() {
        if (!parametr) return;
        std::cout << "Трек остановлен." << std::endl;
        parametr = 0;
    }
};

int main() {
    system("chcp 65001");
    std::cout << "Реализация имитации аудиоплеера." << std:: endl;
    std::cout << std:: endl;
    Player* on = new Player;
    std::cout << "Список доступных команд:" << std:: endl;
    std::cout << "play" << std::endl;
    std::cout << "pause" << std::endl;
    std::cout << "stop" << std::endl;
    std::cout << "next" << std::endl;
    std::cout << "exit" <<std::endl;
    std::cout << std::endl;
    std::cout << "Список треков:" << std:: endl;
    for (int i = 0; i < n; ++i) std::cout << "Имя: " << on->tracks[i].name << std::endl;
    std::cout << std::endl;
    std::cout << "Введите команду: ";
    std::string comand;
    std::cin >> comand;
    while (comand != "exit") {
        if (comand == "play") {
            on->play();
        }
        else if (comand == "pause") {
            on->pause();
        }
        else if (comand == "next") {
            on->next();
        }
        else if (comand == "stop") {
            on->stop();
        }
        else std::cout << "Неверная команда! Повторите ввод." << std::endl;
        std::cout << "Введите команду: ";
        std::cin >> comand;
    }
    delete on;
    return 0;
}

