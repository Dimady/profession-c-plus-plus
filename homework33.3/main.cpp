#include <iostream>
#include <vector>

template<typename T1, typename T2>
class Registr {
    std::vector<std::pair<T1, T2>> vp;
public:
    ~Registr() = default;
    void add(T1& key, T2& val);
    void remove(T1& key);
    void print() const;
    std::vector<T2> find(T1& key);
};

template<typename T1, typename T2>
void Registr<T1, T2>::add(T1& key, T2& val) {
    vp.push_back(make_pair(key, val));
    std::cout << "Pair added";
}

template<typename T1, typename T2>
void Registr<T1, T2>::remove(T1& key) {
    vp.erase(std::remove_if(vp.begin(), vp.end(), [key](const auto &v) {
        return v.first == key;
    }), vp.end());
}

template<typename T1, typename T2>
void Registr<T1, T2>::print() const {
    for (int i = 0; i < vp.size(); i++)
        std::cout << vp[i].first << " " << vp[i].second << " " << std::endl;
}

template<typename T1, typename T2>
std::vector<T2> Registr<T1, T2>::find(T1& key) {
    std::vector<T2> valResult;
    bool find = false;
    for (int i = 0; i < vp.size(); ++i) {
        if (vp[i].first == key) {
            valResult.push_back(vp[i].second);
            find = true;
        }
    }
    if (!find) {
        std::cout << "Not found key: " << key;
    }
    return valResult;
}

int main() {
    std::string ch;
    Registr<int, std::string> reg;
    int a;
    std::string b;
    while (true) {
        std::cout << "\nadd\nremove\nfind\nprint\nany key to exit:";
        std::cin >> ch;
        if (ch == "add") {
            std::cout << "Add element\nkey: ";
            std::cin >> a;
            std::cout << "value: ";
            std::cin >> b;
            reg.add(a, b);
        } else if (ch == "remove") {
            std::cout << "Remove\nkey: ";
            std::cin >> a;
            reg.remove(a);
        } else if (ch == "find") {
            std::cout << "Find\nkey: ";
            std::cin >> a;
            std::vector<std::string> result = reg.find(a);
            for (auto& a : result) {
                std::cout << a << " ";
            }
            std::cout << std::endl;
        } else if (ch == "print") {
            std::cout << "Print\n";
            reg.print();
        } else {
            std::cout << "Exit";
            break;
        }
    }
}