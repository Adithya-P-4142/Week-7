#include <iostream>
#include <string>

class Shape {
protected:
    std::string color;

public:
    Shape(std::string c) : color(c) {
        std::cout << "1. Shape constructor called (Color: " << color << ")\n";
    }
};

class Polygon : public Shape {
protected:
    int sides;

public:
    Polygon(std::string c, int s) : Shape(c), sides(s) {
        std::cout << "2. Polygon constructor called (Sides: " << sides << ")\n";
    }
};

class Rectangle : public Polygon {
private:
    double area;

public:
    Rectangle(std::string c, double width, double height) 
        : Polygon(c, 4), area(width * height) {
        std::cout << "3. Rectangle constructor called (Area: " << area << ")\n";
    }
};

int main() {
    std::cout << "Creating a Rectangle object:\n";
    Rectangle rect("Blue", 5.0, 4.0);
    return 0;
}