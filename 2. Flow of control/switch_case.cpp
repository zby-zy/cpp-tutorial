#include <iostream>
using namespace std;

int main() {
    int x = 6;

    switch (x)
    {
        case 1:
            std::cout << "x is 1" << std::endl;
            break;
        case 2:
        case 3:
            std::cout << "x is 2 or 3" << std::endl;  
            break:
    default:
        std::cout << "x is not 1, 2, or 3" << std::endl;
        break;
    }
    
    return 0;
}