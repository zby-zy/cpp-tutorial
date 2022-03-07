#include <iostream>
using namespace std;

int main() {
    int x = 6;
    int y = 2;

    if (x > y)
    {
        std::cout << "x is greater than y" << std::endl;
    }
    else if (y > x)
    {
        std::cout << "y is greater than x" << std::endl;
    }
    else
        std::cout << "x and y are equal" << std::endl;    

    return 0;   

}