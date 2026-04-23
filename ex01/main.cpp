#include "iter.hpp"

void print(int const &x)
{
    std::cout << x << std::endl;
}
int main(void)
{
    int arr[] = {0,1,2,3,4};
    iter(arr,5,print);
    return 0;
}