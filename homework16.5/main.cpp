#include <iostream>
#include <sstream>
enum Panel {
        POWER = 1 << 0,
        OUTLETS = 1 << 1,
        LIGHT_INSIDE = 1 << 2,
        LIGHT_GARDEN = 1 << 3,
        HEATING_INSIDE = 1 << 4,
        HEATING_WATERPIPE = 1 << 5,
        CONDITIONER = 1 << 6,
    };

void printStatus(int status, const int hour) {
    std::string currentStatus {" Текущий статус:"};
    if (status & POWER)
        currentStatus += "POWER:   on\n";
    else
        currentStatus += "POWER:   off\n";
    if (status & OUTLETS)
        currentStatus += "OUTLETS: on\n";
    else
        currentStatus += "OUTLETS: off\n";

    if (status & LIGHT_INSIDE) {
        int lightTemperature = 5000;
        if (hour >= 16 && hour < 20)
            lightTemperature -= (hour - 16) * 575;
        else if (hour >= 20 && hour <= 23)
            lightTemperature = 2700;
        currentStatus += "LIGHT_INSIDE: " +
                         std::to_string(lightTemperature) + "\n";
    } else {
        currentStatus += "LIGHT_INSIDE: off\n";
    }
    if (status & LIGHT_GARDEN)
        currentStatus += "LIGHT_GARDEN: on\n";
    else
        currentStatus += "LIGHT_GARDEN: off\n";

    if (status & HEATING_INSIDE)
        currentStatus += "HEATING_INSIDE:    on\n";
    else
        currentStatus += "HEATING_INSIDE:    off\n";
    if (status & HEATING_WATERPIPE)
        currentStatus += "HEATING_WATERPIPE: on\n";
    else
        currentStatus += "HEATING_WATERPIPE: off\n";
    if (status & CONDITIONER)
        currentStatus += "CONDITIONER: on\n";
    else
        currentStatus += "CONDITIONER: off\n";
    std::cout << currentStatus << std::endl;
}

int main() {
    system("chcp 65001");
    std::cout << " Умный дом." << std::endl;
    char status;  // current status of panel
    for (int timeSimulation = 0; timeSimulation < 48; ++timeSimulation) {
        int currentHour = timeSimulation % 24;
        std::cout << " Текущий час: " << currentHour << std::endl;
        std::cout << " Введите статус:";
        std::string textStatus;
        std::getline(std::cin, textStatus);
        std::cout << std::endl;
        std::stringstream statusPanel;
        statusPanel << textStatus;
        double temperatureOutside;
        double temperatureInside;
        std::string movingOutside;
        std::string lightInside;
        statusPanel >> temperatureOutside;
        statusPanel >> temperatureInside;
        statusPanel >> movingOutside;
        statusPanel >> lightInside;
        if (!(status & POWER)) status |= (POWER | OUTLETS);
        if (temperatureOutside < 0)
            status |= HEATING_WATERPIPE;
        else if ((status & HEATING_WATERPIPE) && temperatureOutside > 5)
            status &= ~HEATING_WATERPIPE;
        if (temperatureInside < 22)
            status |= HEATING_INSIDE;
        else if ((status & HEATING_INSIDE) && temperatureInside >= 25)
            status &= ~HEATING_INSIDE;
        if (temperatureInside >= 30)
            status |= CONDITIONER;
        else if ((status & CONDITIONER) && temperatureInside <= 25)
            status &= ~CONDITIONER;
        if ("yes" == movingOutside && (currentHour > 16 || currentHour < 5))
            status |= LIGHT_GARDEN;
        else if (status & LIGHT_GARDEN)
            status &= ~LIGHT_GARDEN;
        if ("on" == lightInside)
            status |= LIGHT_INSIDE;
        else if (status & LIGHT_INSIDE)
            status &= ~LIGHT_INSIDE;
        printStatus(status, currentHour);
    }
    std::cout << " Моделирование завершено. Все датчики выключены." << std::endl;
    status = 0;
    printStatus(status, 0);
    std::cout << std::endl;
    return 0;
}

