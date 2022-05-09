#include <iostream>
#include "gpu.h"

void display(double *arr, int length) {
    for (int i = 0; i < length; ++i) {
        std::cout << arr[i] << " ";
    }
}