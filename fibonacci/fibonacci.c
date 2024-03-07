// Owner: Arvin Singh

#include "fibonacci.h"

int fibonacci(int n) {
    // O(2^n) time complexity 
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else {
        return fibonacci(n - 1) + fibonacci(n - 2);
    }

}