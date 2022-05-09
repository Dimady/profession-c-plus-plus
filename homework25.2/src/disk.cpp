#include <iostream>
#include <fstream>
#include "disk.h"

constexpr char* filename = "C:\\skillbox\\profession-c-plus-plus\\homework25.2\\data.txt";

void save(double *arr, int length) {
    std::ofstream data(filename);
    if (!data.is_open()) {
        std::cout << "Ошибка открытия файла data.txt";
        return;
    }
    for (int i = 0; i < length; ++i) {
        data << arr[i] << std::endl;
    }
    data.close();
    return;
}

void load(double *arr, int length) {
    std::ifstream data(filename);
    if (!data.is_open()) {
        std::cout << "Ошибка открытия файла data.txt";
        return;
    }
    for (int i = 0; i < length; ++i) {
        data >> arr[i];
    }
    data.close();
    return;
}