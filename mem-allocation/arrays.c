// Owner: Arvin Singh
#include "arrays.h"

double mean(int length, int *arr) {
    int sum = 0;
    for (int i = 0; i < length; i++) {
        sum += arr[i];
    }
    return (double)sum / length;
}