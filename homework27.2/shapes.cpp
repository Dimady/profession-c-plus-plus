#include "shapes.h"
#include <cmath>
#include <iostream>

void Shape::display() {
    std::cout << "Площадь: " << getSquare() << std::endl;
    colors();
    frames();
}

void Shape::colors() {
    if (getColor() == Colors::NONE) {
        std::cout << "Цвет: None" << std::endl;
    } else if (getColor() == Colors::RED) {
        std::cout << "Цвет:  Red" << std::endl;
    } else if (getColor() == Colors::BLUE) {
        std::cout << "Цвет: Blue" << std::endl;
    } else if (getColor() == Colors::GREEN) {
        std::cout << "Цвет: Green" << std::endl;
    }
}

//******** Point ********
Point::Point(int x, int y) : x(x), y(y) {
}

void Point::setPoint(int x, int y) {
    this->x = x;
    this->y = y;
}

//******** Shape ********
Shape::Shape(Point point, Colors color) : point(point), color(color){}

Colors Shape::getColor() {
    return color;
}

void Shape::setPoint(Point point) {
    this->point = point;
}

void Shape::setColor(Colors color) {
    this->color = color;
}

//******** Circle ********
Circle::Circle(Point point, Colors color, double radius) :
        Shape(point, color), radius(radius) {
}

double Circle::getSquare() {
    return (M_PI * radius * radius);
}

void Circle::frames() {
    std::cout << "Ширина рамки: " << radius + 2 << std::endl;
    std::cout << "Высота рамки: " << radius + 2 << std::endl;
}

//******** Triangle ********
Triangle::Triangle(Point point, Colors color, double side) :
        Shape(point, color), side(side) {
}

double Triangle::getSquare() {
    return ((side * side * sqrt(3))/4);
}

void Triangle::frames() {
    std::cout << "Ширина рамки: " << side + 2 << std::endl;
    std::cout << "Высота рамки: " << side + 2 << std::endl;
}

//******** Square ********
Square::Square(Point point, Colors color, double side) :
        Shape(point, color), side(side) {
}

double Square::getSquare() {
    return (side * side);
}

void Square::frames() {
    std::cout << "Ширина рамки: " << side + 2 << std::endl;
    std::cout << "Высота рамки: " << side + 2 << std::endl;
}

//******** Rectangle ********
Rectangle::Rectangle(Point point, Colors color, double width, double height) :
        Shape(point, color), width(width), height(height) {
}

double Rectangle::getSquare() {
    return (width * height);
}

void Rectangle::frames() {
    std::cout << "Ширина рамки: " << width + 2 << std::endl;
    std::cout << "Высота рамки: " << height + 2 << std::endl;
}