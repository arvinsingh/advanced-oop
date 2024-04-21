// Owner: Arvin Singh

#ifndef CAT_H
#define CAT_H

#include <iostream>
#include <string>
#include <functional> // for std::hash
#include <sstream> // for std::stringstream

class Cat {
private:
    std::string name;
    unsigned int lives;

public:
    Cat();
    Cat(std::string name);
    Cat(const std::string& name, unsigned int lives);
    
    // Getters
    const std::string& getName() const;
    unsigned int getLives() const;

    // Setters
    void setName(const std::string& name);
    void setLives(unsigned int lives);

    // Friend ostream,equality & comparasion operator
    friend std::ostream& operator<<(std::ostream& os, const Cat& cat);
    friend bool operator==(const Cat &left, const Cat &right);
    friend bool operator<(const Cat &left, const Cat &right);
};

// Hash function for Cat
namespace std {
    template <>
    struct hash <Cat> {
        size_t operator()(const Cat& obj) const {
            stringstream ss;
            ss << obj.getName() << obj.getLives();
            return std::hash<std::string>{}(ss.str());
        }
    };
}

#endif // CAT_H
