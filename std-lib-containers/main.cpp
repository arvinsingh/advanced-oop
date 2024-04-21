// -----------------------------------------------------
// 
// (c) Martin Porcheron
//     Thomas Reitmaier
//     thomas.reitmaier@swansea.ac.uk
// Modified by Arvin Singh
// -----------------------------------------------------



#include <iostream>
#include <set>
#include <unordered_set>


#include "cat.h"

int main(int argc, char* argv []) {
  Cat a("Garfield" , 42);
  
  std::cout << std::hash<Cat>()(a) << " = " << a << std:: endl;

  // Note the double ()() syntax!

  // std::hash <Cat>() default constructs an
  // object of type std::hash<Cat>
  
  // std::hash<Cat>()(a) invokes the call
  // operator () on that object with parameter
  
  // std::hash<Cat>()(a) returns an unsigned long integer

  std::unordered_set <Cat> unique_cats;
  unique_cats.insert(Cat("Garfield",  42));
  unique_cats.insert(Cat("Garfield",  10));
  unique_cats.insert(Cat("Catbert",   666));
  unique_cats.insert(Cat("Toothless", 13));
  unique_cats.insert(Cat("Garfield",  42)); 
  unique_cats.insert(Cat("Garfield",  42));

  std::cout << std::endl << "Unique Cats" << std::endl;
  for (auto it = unique_cats.begin(); it != unique_cats.end(); it++) {
    std::cout << *it << std::endl;
  }

  std::set <Cat> unique_cats_2;
  unique_cats_2.insert(Cat("Garfield",  42));
  unique_cats_2.insert(Cat("Garfield",  10));
  unique_cats_2.insert(Cat("Catbert",   666));
  unique_cats_2.insert(Cat("Toothless", 13));
  unique_cats_2.insert(Cat("Garfield",  42)); 
  unique_cats_2.insert(Cat("Garfield",  42));

  std::cout << "Unique Ordered Cats" << std::endl;
  for (auto it2 = unique_cats_2.begin(); it2 != unique_cats_2.end(); it2++) {
    std::cout << *it2 << std::endl;
  }

  return 0;
}
