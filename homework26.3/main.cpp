#include <iostream>

constexpr int xx = 80, yy = 50;

class Monitor
{
public:
    int x;
    int y;
    int width;
    int height;
};

Monitor myMonitor;

class Command
{
public:
    void move ()
    {
        int newX, newY;
        std::cout << "Введите вектор смещения окна: " << std::endl;
        std::cin >> newX >> newY;
        if (std::cin.fail()) {
            std::cerr << "Некорректный ввод данных!" << std::endl;
            exit(0);
        }
        while ((newX + myMonitor.width) > xx && ((newY + myMonitor.height) > yy))
        {
            std::cout << "Некорректный ввод данных! Повторите ввод." << std::endl;
            std::cout << "Введите новое начало: " << std::endl;
            std::cin >> newX >> newY;
        }
        myMonitor.x += newX;
        myMonitor.y += newY;
        std::cout << "Новые координаты окна: " << myMonitor.x << ", " << myMonitor.y << std:: endl;
    };

    void resize ()
    {
        int newWidth, newHeight;
        std::cout << "Введите новую ширину и новую высоту окна: ";
        std::cin >> newWidth >> newHeight;
        if (std::cin.fail()) {
            std::cerr << "Некорректный ввод данных!" << std::endl;
            exit(0);
        }
        while ((myMonitor.x + newWidth) > xx && (myMonitor.y + newHeight) > yy)
        {
            std::cout << "Некорректный ввод данных! Повторите ввод." << std::endl;
            std::cin >> newWidth >> newHeight;
        }
        myMonitor.width = newWidth;
        myMonitor.height = newHeight;
        std::cout << "Новые размеры окна: " << myMonitor.width << ", " << myMonitor.height << std:: endl;
    };
    void display ()
    {
        for (int i = 0; i < yy; i++)
        {
            for (int j = 0; j < xx; j++)
            {
                if (i >= myMonitor.y && i <= (myMonitor.y + myMonitor.height)
                   && j >= myMonitor.x && j <= (myMonitor.x + myMonitor.width)) std::cout << "1";
                else std::cout << "0";
            }
            std::cout << std::endl;
        }
    };
};

int main() {
    system("chcp 65001");
    std::cout << "Реализация программы управления окном рабочего стола." << std:: endl;
    std::cout << std:: endl;
    myMonitor.x = 10;
    myMonitor.y = 10;
    std::cout << "Начальные координаты окна: " << myMonitor.x << ", " << myMonitor.y << std:: endl;
    myMonitor.width = xx / 2;
    myMonitor.height = yy / 2;
    std::cout << "Начальные размеры окна: " << myMonitor.width << ", " << myMonitor.height << std:: endl;
    std::cout << std:: endl;
    std::string answer;
    Command myCommand;
    std::cout << "Список доступных команд:" << std:: endl;
    std::cout << "move" << std::endl;
    std::cout << "resize" << std::endl;
    std::cout << "display" << std::endl;
    std::cout << "exit" << std::endl;
    std::cout << std:: endl;
    std::cout << "Введите команду: ";
    std::cin >> answer;
    while (answer != "exit")
    {
        if (answer == "move") myCommand.move();
        else if (answer == "resize") myCommand.resize();
        else if (answer == "display") myCommand.display();
        else std::cout << "Неверная команда! Повторите ввод.";
        std::cout << std:: endl;
        std::cout << "Введите команду: ";
        std::cin >> answer;
    }
    return 0;
}