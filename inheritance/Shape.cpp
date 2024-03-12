// Owner: Arvin Singh


#include <sstream>
#include <cmath>
#include "Shape.h"

// Circle implementation
Circle::Circle(double x, double y, double r) : x(x), y(y), r(r) {}

std::string Circle::to_string() const {
    std::stringstream sstr;
    sstr << "Circle centered at (" << x << ", " << y << ") with radius " << r;
    return sstr.str();
}

void Circle::centre_at(double x, double y) {
    this->x = x;
    this->y = y;
}


// Rectangle implementation
Rectangle::Rectangle(double x0, double y0, double x1, double y1) : x0(x0), y0(y0), x1(x1), y1(y1) {}

std::string Rectangle::to_string() const {
    double width = x1 - x0;
    double height = y0 - y1; // y0 is the top, y1 is the bottom

    std::stringstream sstr;
    sstr << "Rectangle at [(" << x0 << ", " << y0 << "), (" << x1 << ", " << y1 << ")] with width " << width << ", height " << height;
    return sstr.str();
}

void Rectangle::centre_at(double x, double y) {
    double current_center_x = (x0 + x1) / 2.0;
    double current_center_y = (y0 + y1) / 2.0;

    double dx = x - current_center_x;
    double dy = y - current_center_y;

    x0 += dx;
    x1 += dx;
    y0 += dy;
    y1 += dy;
}


// Triangle implementation
Triangle::Triangle(double x0, double y0, double x1, double y1, double x2, double y2)
    : x0(x0), y0(y0), x1(x1), y1(y1), x2(x2), y2(y2) {}

std::string Triangle::to_string() const {
    double side1 = calculate_distance(x0, y0, x1, y1);
    double side2 = calculate_distance(x1, y1, x2, y2);
    double side3 = calculate_distance(x2, y2, x0, y0);

    std::stringstream sstr;
    sstr << "Triangle at [(" << x0 << ", " << y0 << "), (" << x1 << ", " << y1 << "), (" << x2 << ", " << y2 << ")] with side lengths " 
                            << side1 << ", " << side2 << 
                            ", and " << side3;
    return sstr.str();
}


void Triangle::centre_at(double x, double y) {
    double current_centroid_x = (x0 + x1 + x2) / 3.0;
    double current_centroid_y = (y0 + y1 + y2) / 3.0;

    double dx = x - current_centroid_x;
    double dy = y - current_centroid_y;

    x0 += dx;
    x1 += dx;
    x2 += dx;

    y0 += dy;
    y1 += dy;
    y2 += dy;
}

double Triangle::calculate_distance(double x0, double y0, double x1, double y1) const {
    return std::sqrt(std::pow(x1 - x0, 2) + std::pow(y1 - y0, 2));
}