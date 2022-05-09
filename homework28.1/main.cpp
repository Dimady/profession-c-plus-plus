#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <limits>

struct rating {
    std::string name;
    int finish;
};

std::vector<rating> ratings;
std::mutex mtx;

void swimmer(std::string name, int speed);

using namespace std;

int main() {
    system("chcp 65001");
    vector<string> swName(6);
    vector<int> swSpeed(6);
    for (int i = 0; i < swName.size(); ++i) {
        cout << "Имя пловца " << i + 1 << ": ";
        getline(cin, swName[i]);
        cout << "Скорость пловца " << i + 1 << ": ";
        cin >> swSpeed[i];
        cin.ignore(numeric_limits<int>::max(), '\n');
    }
    std::vector<std::thread> threads(6);
    for (int i = 0; i < threads.size(); ++i) {
        threads[i] = thread(swimmer, swName[i], swSpeed[i]);
    }
    for (int i = 0; i < threads.size(); ++i) {
        threads[i].join();
    }
    cout << "\n*********** Рейтинг плавания ***********\n";
    mtx.lock();
    for (int i = 0; i < ratings.size(); ++i) {
        cout << ratings[i].name << " \t:\t " << ratings[i].finish << endl;
    }
    mtx.unlock();
    return 0;
}

void swimmer(std::string name, int speed) {
    int distance = 0;
    while (distance < 100) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        distance += speed;
        if (distance > 100) distance = 100;
        std::cout << "Расстояние " << name << ": " <<  distance << std::endl;
    }
    rating tmp;
    tmp.name = name;
    tmp.finish = (distance + speed - 1) / speed;
    mtx.lock();
    ratings.push_back(tmp);
    mtx.unlock();
}
