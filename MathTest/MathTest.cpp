#include <iostream>
#include <cstdlib>
#include <ctime>
#include "mlib.h"

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "Hello! Welcome to MathTest App!" << std::endl;

    MathTest test(5, 1, 20, '+');
    test.run();

    return 0;
}