#include <iostream>

#define FULLFILL(a) \
for (int i = 0; i < 10; i++) \
{\
std::cout << "Введите количество пассажиров в " << i + 1 << " вагоне: ";\
std::cin >> a[i];\
}\

#define EMPTYWAGON(a) \
for (int i = 0; i < 10; i++) \
{\
std::cout << "Информация о " << i + 1 <<" вагоне: " << std::endl;\
if (a[i] < 20) {\
std::cout << "вагон с пустыми пассажирскими местами" << std::endl;\
} else if (a[i] > 20) {\
std::cout << "вагон излишне заполнен" << std::endl;\
} else {              \
std::cout << "количество пассажиров в вагоне оптимально" << std::endl;                      \
}\
}\

#define SUMWAGON(a) \
int sum = 0; \
for (int i = 0; i < 10; i++) \
{\
sum += a[i];\
}\
std::cout << "Общее количество пассажиров: " << sum << std::endl;\

int main() {
    system("chcp 65001");
    int a[10];
    FULLFILL (a);
    EMPTYWAGON(a);
    SUMWAGON(a);
    return 0;
}

