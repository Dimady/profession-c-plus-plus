#include "cpu.h"

double compute(double *arr, int length) {
    double sum = 0;
    for (int i = 0; i < length; ++i) {
        sum += arr[i];
    }
    return sum;
}