#pragma once

#include <iostream>

class Point {
    int x;
    int y;
public:
    Point() = default;
    Point(int x, int y);
    void setPoint(int x, int y);
};

enum class Colors {
    NONE,
    RED,
    BLUE,
    GREEN
};

class Shape {
private:
    Point point;

public:
    Shape(Point point, Colors color);
    Colors getColor();
    virtual double getSquare() = 0;
    void setPoint(Point point);
    void setColor(Colors color);
    void colors();
    Colors color;
    void display();
    virtual void frames() = 0;
};

//circle, square, triangle, rectangle

class Circle: public Shape {
private:
    double radius;

public:
    Circle(Point point, Colors color, double radius);
    double getSquare();
    void frames();
};

class Triangle: public Shape {
private:
    double side;

public:
    Triangle(Point point, Colors color, double side);
    double getSquare();
    void frames();
};

class Square: public Shape {
private:
    double side;

public:
    Square(Point point, Colors color, double side);
    double getSquare();
    void frames();
};

class Rectangle: public Shape {
private:
    double width;
    double height;

public:
    Rectangle(Point point, Colors color, double, double);
    double getSquare();
    void frames();
};