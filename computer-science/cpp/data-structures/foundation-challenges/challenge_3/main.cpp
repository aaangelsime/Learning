/*
Write a function that takes a pointer to an int 
and recursively add all numbers from 1 up to that value,
storing the result back through the pointer

requirements:
- the function returns void - no return value
- the final answer must be stored at the address result points to
- no loops 
- base case: when n == 0, do nothing and return
*/

#include <iostream>

int sum(int x)
{
    if(x == 1) return 1;
    return x + (x - 1);
}

int main()
{
    std::cout << sum(5);

    return 0;
}