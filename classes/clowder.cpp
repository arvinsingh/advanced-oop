// Owner: Arvin Singh

#include <iostream>
#include <string>
#include "cat.h"

int main(int argc, char* argv[]) {
    const int numCats = argc / 2;
    const int lastCatLives = (argc % 2 == 0) ? 9 : std::stoi(argv[argc - 1]);

    std::cout << "Allocated clowder of size: " << numCats << std::endl;
    Cat* clowder = new Cat[numCats];
    
    for (int i = 0; i < numCats; i++) {
        std::string name = argv[i * 2 + 1];
        int lives = (i == numCats - 1) ? lastCatLives : std::stoi(argv[i * 2 + 2]);

        clowder[i].set_name(name);
        clowder[i].set_lives(lives);
    }

    for (int i = 0; i < numCats; i++) {
        std::cout << clowder[i].get_name() << " has " << clowder[i].get_lives() << " lives." << std::endl;
    }

    delete[] clowder;

    return 0;
}