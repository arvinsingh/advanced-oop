// Owner: Arvin Singh

#include <iostream>
#include <string>
#include "cat.h"


Cat::Cat() : name("Tom"), lives(9) {
    std::cout << "Default constructor called..." << std::endl;
}

Cat::Cat(const std::string& catName) : name(catName), lives(9) {
    std::cout << "Constructor called with name: " << name << std::endl;
}

Cat::Cat(const std::string& catName, unsigned int catLives) : name(catName), lives(catLives) {
    std::cout << "Constructor called with name and lives: " << name << ", " << lives << std::endl;
}

Cat::~Cat() {
    std::cout << "Destructor called..." << std::endl;
}

const std::string& Cat::get_name() const {
    return name;
}

const unsigned int& Cat::get_lives() const {
    return lives;
}

void Cat::set_name(const std::string& newName) {
    std::cout << "set_name called..." << std::endl;
    name = newName;
}

void Cat::set_lives(const unsigned int& newLives) {
    std::cout << "set_lives called..." << std::endl;
    if (newLives >= lives) {
        return;
    }
    if (lives > 0 && newLives == 0) {
        std::string newName = "The Cat formerly known as " + name;
        set_name(newName);
    }
    lives = newLives;
}
