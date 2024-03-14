#include "cat.h"

Cat::Cat(const std::string& name, unsigned int lives) : name(name), lives(lives) {}

// Getter implementations
const std::string& Cat::getName() const {
    return name;
}

unsigned int Cat::getLives() const {
    return lives;
}

// Setter implementations
void Cat::setName(const std::string& name) {
    this->name = name;
}

void Cat::setLives(unsigned int lives) {
    this->lives = lives;
}

// Friend ostream operator implementation
std::ostream& operator<<(std::ostream& os, const Cat& cat) {
    os << "Name: " << cat.name << ", Lives: " << cat.lives;
    return os;
}
