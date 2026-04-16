#include <iostream>

int main()
{
    int num = 1;
    int* x = &num;
    std::cout << x << " " << num << std::endl;
    std::cout << &x << " " << &num;

    return 0;
}