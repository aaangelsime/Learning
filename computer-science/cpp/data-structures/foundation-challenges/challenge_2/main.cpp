#include <iostream>

int sum_down_front(int n)
{
    if (n == 1) return 1; // base case
    return n + sum_down_front(n - 1); // recursice case
}
int main()
{

    std::cout << sum_down_front(6);
    return 0;
}