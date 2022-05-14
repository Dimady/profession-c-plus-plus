#include <iostream>
#include <vector>
#include <fstream>
#include "nlohmann/json.hpp"

nlohmann::json::iterator find(nlohmann::json& db, std::string name) {
    auto it = db.begin();
    for (; it != db.end(); ++it) {
        std::vector<std::string> starring = it.value()["starring"];
        for (auto& a : starring) {
            if (a == name) {
                return it;
            }
        }
    }
    return it;
}

int main() {
    system("chcp 65001");
    std::ifstream file("filmsBD.json");
    nlohmann::json fdb;
    file >> fdb;
    std::string name = "Al Pacino";
    std::cout << "Найти роли в filmsDB:" << std::endl;
    nlohmann::json::iterator itFind;
    itFind = find(fdb, name);
    if (itFind != fdb.end()) {
        std::cout << name << std::endl;
        std::cout << "Фильмы: " << itFind.key() << std::endl;
        std::cout << "Даты выпуска: " << itFind.value()["date"].get<int>() << std::endl;
    } else {
        std::cout << "Не найдено" << std::endl;
    }
}
