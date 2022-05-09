#include <iostream>
#include <cstdlib>
#include <thread>
#include <ctime>
#include <vector>
#include <mutex>

enum class Menu{PIZZA, SOUP, STEAK, SALAD, SUSHI};

std::string getDishes(const int order) {
    switch (order) {
        case 0: return "PIZZA";
        case 1: return "SOUP";
        case 2: return "STEAK";
        case 3: return "SALAD";
        case 4: return "SUSHI";
    }
    return "ERROR: Wrong order!";
}
std::mutex mtx_orders;
std::mutex mtx_delivery;
std::vector<int> orders;
std::vector<int> delivery;

void customer() {
    std::srand(time(nullptr));
    int orderTime = rand() % 6 + 5;
    std::this_thread::sleep_for(std::chrono::seconds(orderTime));
     int order = rand() % 5;
     mtx_orders.lock();
     orders.push_back(order);
     mtx_orders.unlock();
     std::cout << getDishes(order) << " ordered." << std::endl;
}

void kitchen() {
    if (!orders.empty()) {
        std::srand(time(nullptr));
        mtx_orders.lock();
        mtx_delivery.lock();
        while(!orders.empty()) {
            int cookingTime = rand() % 11 + 5;
            std::this_thread::sleep_for(std::chrono::seconds(cookingTime));
            int order = orders.back();
            delivery.push_back(order);
            std::cout << getDishes(order) << " is cooked." << std::endl;
            orders.pop_back();
        }
        mtx_delivery.unlock();
        mtx_orders.unlock();
    }
}

void courier(int &counter) {
    if (!delivery.empty()) {
        std::this_thread::sleep_for(std::chrono::seconds(30));
        mtx_delivery.lock();
        while(!delivery.empty()) {
            std::cout << getDishes(delivery.back()) << " delivered." << std::endl;
            delivery.pop_back();
            ++counter;
        }
        mtx_delivery.unlock();
    }
}

int main() {
    int counter = 0;
    while(counter < 10) {
        std::thread order(customer);
        std::thread kitch(kitchen);
        kitch.detach();
        std::thread deliveryman(courier, std::ref(counter));
        order.join();
        if(kitch.joinable()) kitch.join();
        deliveryman.join();
    }
     return 0;
}
