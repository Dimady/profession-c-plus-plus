#include<iostream>

#define ONE 1
#define TWO 2
#define THREE 3
#define FOUR 4
#define FIVE 5
#define SIX 6
#define SEVEN 7
#define DAY_ONE "понедельник"
#define DAY_TWO "вторник"
#define DAY_THREE "среда"
#define DAY_FOUR "четверг"
#define DAY_FIVE "пятница"
#define DAY_SIX "суббота"
#define DAY_SEVEN "воскресенье"
#define ERROR std::cout << "День недели установлен неправильно!" << std::endl;
#define MESSAGE std::cout << "Введите день недели:";
#define PRINT_DEY(x) std::cout<<DAY_## x <<std::endl;

int main() {
    system("chcp 65001");
    int day;
    MESSAGE
    std::cin >> day;
    switch(day) {
        case ONE:
            PRINT_DEY(ONE)
            break;
        case TWO:
            PRINT_DEY(TWO)
            break;
        case THREE:
            PRINT_DEY(THREE)
            break;
        case FOUR:
            PRINT_DEY(FOUR)
            break;
        case FIVE:
            PRINT_DEY(FIVE)
            break;
        case SIX:
            PRINT_DEY(SIX)
            break;
        case SEVEN:
            PRINT_DEY(SEVEN)
            break;
        default:
            ERROR
            break;
    }
}
