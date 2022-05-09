#include <iostream>
#include <cstring>

bool substr(const char* a, const char* b)
{
    int la = strlen(a), lb = strlen(b);
    for (int i = 0; i < la - lb; ++i)
    {
        int j = 0;
        while (j < lb && (*(a + i + j) == *(b + j)))
        {
            ++j;
        }
        if (j == lb) return true;
    }
    return false;
}

int main() {
    const char* a = "Hello world";
    const char* b = "wor";
    const char* c = "banana";
    bool check;
    check = substr (a, b);
    if (check) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
    check = substr (a, c);
    if (check) std::cout << "true" << std::endl;
    else std::cout << "false" << std::endl;
    return 0;
}