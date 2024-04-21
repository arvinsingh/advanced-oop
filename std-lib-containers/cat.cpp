// Owner: Arvin Singh

#include "cat.h"

Cat::Cat(): Cat("Oggy", 10) {}
Cat::Cat(std::string name): Cat(name, 10) {}
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

// Friend equality operator implementation
bool operator==(const Cat &left, const Cat &right) {
  return left.getName()  == right.getName()   &&
         left.getLives() == right.getLives();
}

// Friend comparasion operator implementation
bool operator<(const Cat &left, const Cat &right) {
  if (left.getName() == right.getName()) {
    return left.getLives() < right.getLives();
  }
  return left.getName() < right.getName();
}