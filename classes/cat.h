// Owner: Arvin Singh

#pragma once

#include <string>


class Cat {
private:
    std::string name;
    unsigned int lives;

public:
    Cat();
    Cat(const std::string& name);
    Cat(const std::string& name, unsigned int lives);
    ~Cat();

    const std::string& get_name() const;
    const unsigned int& get_lives() const;

    void set_name(const std::string& newName);
    void set_lives(const unsigned int& newLives);
    
};