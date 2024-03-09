// Owner: Arvin Singh

#include <stdio.h>
#include "timestable.h"
#include "arrays.h"


void generateTable(int num, int *table) {
	int i;
	for (i = 0; i <= MAX_TABLE_SIZE; i++) {
		table[i] = i * num;
	}
}

void printTable(int num, int *table) {
	printf("%-2d times table\n--------------\n", num);
	int i;
	for (i = 0; i <= MAX_TABLE_SIZE; i++) {
		printf("%-2d * %-2d = %d\n", num, i, *(table+i));
	}
	printf("\n");
    double meanValue = mean(MAX_TABLE_SIZE, table);
    printf("The mean for this table is %f\n\n", meanValue);
}

void printTables(int **tables) {
    // Print all the times tables from 0 to MAX_TIMES_TABLE
    int i;
    for (i = 0; i <= MAX_TIMES_TABLE; i++) {
        printTable(i, tables[i]);
    }
}