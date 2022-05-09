#include <iostream>
#include "shapes.h"

using namespace std;

void inputDate(Point &point, Colors &color);

int main() {
    system("chcp 65001");
    Shape* shape;
    cout << "Введите команду (circle/square/triangle/rectangle): ";
    string command;
    getline(cin, command);
    if (command == "circle") {
        Point point;
        Colors color;
        inputDate(point, color);
        cout << "Введите радиус: ";
        int radius;
        cin >> radius;
        Circle circle(point, color, radius);
        shape = &circle;
        shape->display();
    } else if (command == "square") {
        Point point;
        Colors color;
        inputDate(point, color);
        cout << "Введите сторону: ";
        int side;
        cin >> side;
        Square square(point, color, side);
        shape = &square;
        shape->display();
    } else if (command == "triangle") {
        Point point;
        Colors color;
        inputDate(point, color);
        cout << "Введите сторону: ";
        int side;
        cin >> side;
        Triangle triangle(point, color, side);
        shape = &triangle;
        shape->display();
    } else if (command == "rectangle") {
        Point point;
        Colors color;
        inputDate(point, color);
        cout << "Введите ширину и высоту: ";
        int width;
        int height;
        cin >> width >> height;
        Rectangle rectangle(point, color, width, height);
        shape = &rectangle;
        shape->display();
    } else {
        cout << "Такой команды нет!" << endl;
    }
    return 0;
}

void inputDate(Point &point, Colors &color) {
    cout << "Введите координаты центра (x, y): ";
    int x;
    int y;
    cin >> x >> y;
    point.setPoint(x, y);
    cout << "Введите номер соответствующего цвета: "
            << "\n0 - No color"
            << "\n1 - Red"
            << "\n2 - Blue"
            << "\n3 - Green" << endl;
    int iColor;
    cin >> iColor;
    if (iColor == 1) {
        color = Colors::RED;
    } else if (iColor == 2) {
        color = Colors::BLUE;
    } else if (iColor == 3) {
       color = Colors::GREEN;
    } else {
        color = Colors::NONE;
    }
}
