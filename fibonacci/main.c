// Owner: Arvin Singh
#include <stdio.h>
#include <stdlib.h>
#include "fibonacci.h"

// #define FIBONACCI_NUM 10 //for task2

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Invalid number of arguments. Please provide a single integer argument.\n");
        return 1;
    }

    int num = atoi(argv[1]);
    int result = fibonacci(num);
    printf("Fibonacci of %d = %d\n", num, result);

}