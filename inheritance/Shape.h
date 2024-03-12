// Owner: Arvin Singh


#pragma once

#include <string>

class Shape {
public:
    Shape() = default;
    virtual ~Shape() = default;

    virtual std::string to_string() const = 0;
    virtual void centre_at(double x, double y) = 0;
};

class Circle : public Shape {
public:
    Circle(double x, double y, double r); // Constructor

    // Implementing pure virtual functions
    virtual std::string to_string() const override;
    virtual void centre_at(double x, double y) override;

private:
    double x, y, r; // Member fields for position and radius
};


class Rectangle : public Shape {
public:
    Rectangle(double x0, double y0, double x1, double y1); // Constructor

    // Implementing pure virtual functions
    virtual std::string to_string() const override;
    virtual void centre_at(double x, double y) override;

private:
    double x0, y0, x1, y1; // Member fields for top-left and bottom-right corners
};

class Triangle : public Shape {
public:
    Triangle(double x0, double y0, double x1, double y1, double x2, double y2); // Constructor

    // Implementing pure virtual functions
    virtual std::string to_string() const override;
    virtual void centre_at(double x, double y) override;

private:
    double x0, y0, x1, y1, x2, y2; // Member fields for three vertices

    // Helper function to calculate the distance between two points (x0, y0) and (x1, y1)
    double calculate_distance(double x0, double y0, double x1, double y1) const;
};