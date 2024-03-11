// Owner: Arvin Singh

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constituency.h"

void constructConstituency(struct Constituency * const obj, 
                            char const *name, 
                            unsigned int* const neighbours, 
                            unsigned int const numNeighbours) {
    obj->name = 0;
    obj->neighbours = 0;
    obj->numNeighbours = numNeighbours;

    obj->name = malloc(strlen(name) + 1);
    if (obj->name == 0) {
        // Handle malloc error
        printf("Error: Memory allocation failed\n");
        exit(-2);
    }
    strcpy(obj->name, name);
    if (numNeighbours > 0) {
        obj->neighbours = malloc(numNeighbours * sizeof(int));
        if (obj->neighbours == NULL) {
            // Handle malloc error
            printf("Error: Memory allocation failed\n");
            free(obj->name);
            obj->name = NULL;
            exit(-2);
        }
        memcpy(obj->neighbours, neighbours, numNeighbours * sizeof(int));
    }
}

void destructConstituency(struct Constituency* const obj) {
    free(obj->name);
    obj->name = 0;
    free(obj->neighbours);
    obj->neighbours = 0;
    obj->numNeighbours = 0;
}

void printConstituency(struct Constituency* const obj) {
    printf("%-20s", obj->name);
    printf(" | %d neighbours | ", obj->numNeighbours);
    printf("[");
    for (int i = 0; i < obj->numNeighbours; i++) {
        printf(" %d ", obj->neighbours[i]);
    }
    printf("]\n");
}

struct Constituency* copyConstituencies(struct Constituency* const constituencies, unsigned int const numConstituencies) {
    struct Constituency* copy = malloc(numConstituencies * sizeof(struct Constituency));
    if (copy == NULL) {
        // Handle malloc error
        printf("Error: Memory allocation failed\n");
        exit(-2);
    }
    int i;
    for (i = 0; i < numConstituencies; i++) {
        constructConstituency(&copy[i], constituencies[i].name, constituencies[i].neighbours, constituencies[i].numNeighbours);
    }    
    return copy;
}