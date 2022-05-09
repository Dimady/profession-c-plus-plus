#include <iostream>

//#define WINTER
//#define SPRING
//#define SUMMER
#define AUTUMN

#ifdef WINTER
int main() {
    std::cout << "Winter" << std::endl;
    return 0;
}
#endif

#ifdef SPRING
int main() {
    std::cout << "Spring" << std::endl;
    return 0;
}
#endif

#ifdef SUMMER
int main() {
    std::cout << "Summer" << std::endl;
    return 0;
}
#endif

#ifdef AUTUMN
int main() {
    std::cout << "Autumn" << std::endl;
    return 0;
}
#endif
