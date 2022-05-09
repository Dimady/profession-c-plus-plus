#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <limits>

struct Train {
    std::string name = "none";
    int speed;
};

std::mutex station;

void moveTrain(const Train &t) {
    std::this_thread::sleep_for(std::chrono::seconds(t.speed));
    if(station.try_lock())
        station.unlock();
    else
        std::cout << "\nПоезд " << t.name << " находится в ожидании прибытия на вокзал" << std::endl;
    station.lock();
    std::cout << "Прибытие поезда " << t.name << std::endl;
    std::string command;
    do {
        std::cout << "Освободите железнодорожный вокзал (depart): ";
        std::getline(std::cin, command);
    } while(command != "depart");
    std::cout << "Отправление поезда " << t.name << std::endl;
    station.unlock();
}

int main() {
    system("chcp 65001");
    std::vector<Train> trains(3);
    std::string name[] = {"A", "B", "C"};
    for(int i = 0; i < trains.size(); ++i) {
        std::cout << "Введите время в пути поезда " << name[i] << ": ";
        int time;
        std::cin >> time;
        std::cin.ignore(std::numeric_limits<int>::max(), '\n');
        trains[i].name = name[i];
        trains[i].speed = time;
    }
    std::vector<std::thread> trainThreads(3);
    for (int i = 0; i < trainThreads.size(); ++i)
        trainThreads[i] = std::thread(moveTrain, trains[i]);
    for (int i = 0; i < trainThreads.size(); ++i)
        trainThreads[i].join();
    return 0;
}

