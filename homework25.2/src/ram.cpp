#include "ram.h"
#include "main.h"

double buffer[n];

void read(double *arr, int length) {
	for(int i = 0; i < length; ++i) {
		arr[i] = buffer[i];
	}
}

void write(double *arr, int length) {
	for(int i = 0; i < length; ++i) {
		buffer[i] = arr[i];
	}
}