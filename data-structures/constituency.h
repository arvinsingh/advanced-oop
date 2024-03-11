// Owner: Arvin Singh

#ifndef CONSTITUENCY_H
#define CONSTITUENCY_H

#pragma pack(1) // This is to ensure that the struct is packed and there is no padding

struct Constituency {
    char* name;
    unsigned int* neighbours;
    unsigned int numNeighbours;
};

void constructConstituency(struct Constituency * const obj, 
                            char const *name,
                            unsigned int* const neighbours,
                            unsigned int const numNeighbours);
void printConstituency(struct Constituency * const obj);
void destructConstituency(struct Constituency * const obj);
struct Constituency* copyConstituencies(struct Constituency* const constituencies, 
                                        unsigned int const numConstituencies);

#endif // CONSTITUENCY_H