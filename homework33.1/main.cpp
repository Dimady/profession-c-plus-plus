#include <iostream>
#include <exception>
#include <map>
#include <iomanip>

struct Item {
    std::string idItem;
    int countItem;
    Item(): idItem("None"), countItem(0) {};
    bool enter();
};

class Basket {
    std::map<std::string, int>* shopDb;
    std::map<std::string, int> basket;
public:
    Basket(std::map<std::string, int>* Db) : shopDb(Db), basket() {};
    ~Basket() = default;
    auto find(Item &item);
    void add(Item& item);
    void remove(Item& item);
    const std::map<std::string, int>* get_ptr() const {
        return &basket;
    }
};

bool Item::enter() {
    std::cout << "Введите артикул продукта или \"exit\" для завершения: ";
    std::cin >> idItem;
    if (idItem == "exit") {
        return false;
    }
    while (true) {
        std::cout << "Введите количество продуктов: ";
        std::cin.exceptions(std::istream::failbit | std::istream::badbit);
        try {
            std::cin >> countItem;
        }
        catch (std::istream::failure) {
            std::cin.clear();
            std::cin.sync();
            std::cout << "Неверный ввод, повторите!" << std::endl;
            continue;
        }
        if (countItem <= 0) {
            std::cout << "сount <= 0, повторите!" << std::endl;
        } else {
            break;
        }
    }
    return true;
}

auto Basket::find(Item& item) {
    auto it = shopDb->find(item.idItem);
    if (it == shopDb->end()) {
        throw std::runtime_error("Продукт не найден\n");
    }
    else return it;
}

void Basket::add(Item& item) {
     if (find(item)->second >= item.countItem) {
         basket[item.idItem] = item.countItem;
         (*shopDb)[item.idItem] -= item.countItem;
         std::cout << "Продукты добавлены в корзину" << std::endl;
     } else {
         throw std::invalid_argument("Столько продуктов нет в магазине\n");
     }
}

void Basket::remove(Item& item) {
    if (find(item)->second <= item.countItem) {
        throw std::invalid_argument("Столько продуктов нет в корзине\n");
    } else {
            basket[item.idItem] -= item.countItem;
            (*shopDb)[item.idItem] += item.countItem;
            std::cout << "Продукты удалены из корзины" << std::endl;
    }
}

void print(const std::map<std::string, int>& db) {
    for (auto& a : db) {
        std::cout << a.first << " -> " << a.second << std::endl;
    }
}

int main() {
    system("chcp 65001");
    std::map<std::string, int> shop;
    Basket basket(&shop);
    Item item;
    std::cout << "Создание БД SHOP" << std::endl;
    while (item.enter()) {
        shop[item.idItem] = item.countItem;
    }
    std::cout << std::endl << "BASKET" << std::endl;
    while (true) {
        std::cout << std::endl << "add item" << std::endl;
        std::cout << "remove item" << std::endl;
        std::cout << "print" << std::endl;
        std::cout << "Введите add, remove или print: ";
        std::string entCh;
        std::cin >> entCh;
        if (entCh == "add") {
            item.enter();
            try {
                basket.add(item);
            }
            catch (std::exception& exc) {
                std::cout << exc.what();
            }
        } else if (entCh == "remove") {
            item.enter();
            try {
                basket.remove(item);
            }
            catch (std::exception& exc) {
                std::cout << exc.what();
            }
        } else if (entCh == "print") {
            std::cout << std::endl << "SHOP" << std::endl;
            print(shop);
            std::cout << std::endl << "BASKET" << std::endl;
            print(*basket.get_ptr());
        } else {
            std::cout << "Неверный ввод, повторите!" << std::endl;
        }
    }
}