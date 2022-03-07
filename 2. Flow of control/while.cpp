#include <iostream>
using namespace std;

int main() {
    int x = 0;

    while (x < 10)
    {
        x = x + 1;

        std::cout << "x is " << x << std::endl;
    }

    return 0;
}