// Owner: Arvin Singh
// -----------------------------------------------------
// CSC371 Advanced Object-Oriented Programming (2023/24)
//
// (c) Martin Porcheron
//     Thomas Reitmaier
//     thomas.reitmaier@swansea.ac.uk
// modified by Arvin Singh
// -----------------------------------------------------

#include <stdio.h>

#include "constituency.h"

int main()
{   
    /*//for test
    struct Constituency test;
    constructConstituency(
        &test,
        "Swansea East",
        (unsigned int[]){1, 2, 3, 4},
        4);
    */

    const int numConstituencies = 5;
    struct Constituency constituencies[numConstituencies];

    constructConstituency(&constituencies[0], "Swansea East", (unsigned int[]){1, 2, 3, 4}, 4);
    constructConstituency(&constituencies[1], "Swansea West", (unsigned int[]){0, 2}, 2);
    constructConstituency(&constituencies[2], "Gower", (unsigned int[]){0, 1, 3}, 3);
    constructConstituency(&constituencies[3], "Neath", (unsigned int[]){0, 2, 4}, 3);
    constructConstituency(&constituencies[4], "Aberavon", (unsigned int[]){0 , 3}, 2);

    // Deep copy the constituencies
    struct Constituency * copy = copyConstituencies(constituencies, numConstituencies);
    int i = 0;
    // Destruct the original constituencies
    for(i = 0; i < numConstituencies; i++) {
        destructConstituency(&constituencies[i]);
    }

    // Find the constituency with the most and fewest bordering constituencies
    const struct Constituency *max = &copy[0];
    const struct Constituency *min = &copy[0];

    // Print the constituencies
    for (i = 0; i < numConstituencies; i++) {
        printConstituency(&copy[i]);
        // calculate max
        if (copy[i].numNeighbours > max->numNeighbours) {
            max = &copy[i];
        }
        // calculate min
        if (copy[i].numNeighbours < min->numNeighbours) {
            min = &copy[i];
        }
    }

    // Print the constituencies with the most and fewest bordering constituencies
    printf("\n%s has the most bordering constituencies: \n", max->name);
    for(i = 0; i < max->numNeighbours; i++) {
        printf("%s\n", copy[max->neighbours[i]].name);
    }
    
    printf("\n%s has the fewest bordering constituencies: \n", min->name);
    for(i = 0; i < min->numNeighbours; i++) {
        printf("%s\n", copy[min->neighbours[i]].name);
    }

    // Destruct the copy
    for (i = 0; i < numConstituencies; i++) {
        destructConstituency(&copy[i]);
    }

    //printConstituency(&test); // for test
    //destructConstituency(&test); // for test

    return 0;
}