// Owner: Arvin Singh

#include <stdio.h>
#include <stdlib.h>
#include "timestable.h"

int main() {
    int *tables[MAX_TIMES_TABLE];

    for (int i = 0; i <= MAX_TIMES_TABLE; i++) {
        tables[i] = malloc(MAX_TABLE_SIZE * sizeof(int));
        if (tables[i] == NULL) {
            printf("Memory allocation failed!\n");
            return -1;
        }
    }

    for (int i = 0; i <= MAX_TIMES_TABLE; i++) {
        generateTable(i, tables[i]);
    }
    
    printTables(tables);

    for (int i = 0; i < MAX_TIMES_TABLE; i++) {
        free(tables[i]);
    }
    return 0;
}
