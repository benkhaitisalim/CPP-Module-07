#pragma once

#include <iostream>

template <typename T>

void iter(T *arr, size_t const size, void (*f)(T const &))
{
    for(size_t i = 0; i < size ; i++)
    {
        f(arr[i]);
    }
}