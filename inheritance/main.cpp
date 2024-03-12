// Owner: Arvin Singh

#include <iostream>
#include "Shape.h"

int main(int argc , char *argv[]) {
    
    // A Circle object
    Shape *x = new Circle (0, 0, 1); // x, y, r
    std::cout << "--For Circle--" << std::endl << x->to_string() << std::endl;
    x->centre_at(2, 3);
    std::cout << x->to_string() << std::endl;
    delete x;

    // A Triangle object
    std::cout << std::endl << "--For Rectangle--" << std::endl;
    Shape *rect = new Rectangle(0, 1, 1, 0);
    std::cout << rect->to_string() << std::endl;
    rect->centre_at(-2.5, 2.5);
    std::cout << rect->to_string() << std::endl;
    delete rect;

    // Combination of shapes
    std::cout << std::endl << "--For 10 shape combinations (circle/triangle/rectangle)--" << std::endl;
    Shape **xs = new Shape*[10];
    xs[0] = new Circle(0, 0, 1);
    xs[1] = new Rectangle(1, 1, 2, 2);
    xs[2] = new Triangle(0, 0, 1, 1, 2, 2);
    xs[3] = new Circle(1, 1, 2);
    xs[4] = new Rectangle(0, 1, 1, 0);
    xs[5] = new Triangle(0, 0, 1, 1, 0, 1);
    xs[6] = new Circle(-5, -1, 5);
    xs[7] = new Rectangle(1, 1, 2, 2);
    xs[8] = new Triangle(4, -3, 5, -2, 4, -2);
    xs[9] = new Triangle(0, 0, 1, 1, 0, 1);

    // Loop over the elements of shape array and call the to_string() function
    for (int i = 0; i < 10; i++) {
        std::cout << xs[i]->to_string() << std::endl;
    }
    
    std::cout << std::endl << "--After moving center--" << std::endl;

    // Loop over the elements of the Shape array and call the centre_at(x, y) functions
    for (int i = 0; i < 10; i++) {
        xs[i]->centre_at(i, i); // move each shape to a different location
        std::cout << xs[i]->to_string() << std::endl;
    }

    // Deallocate each of the Shape objects individually
    for (int i = 0; i < 10; i++) {
        delete xs[i];
    }

    // Deallocate the array of Shape pointers
    delete[] xs;

    return 0;
}