#pragma once 
#include <stdexcept>
#include <iostream>

template <typename T>
class Array 
{
    private :
    T* Data;
    unsigned int length;
    public :
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array& operator=(const Array &other);
    ~Array();
    T& operator[](unsigned int index);
    const T& operator[](unsigned int index) const;
    unsigned int size() const;
};

template <typename T>
Array<T>::Array():Data(nullptr),length(0){}
template <typename T>
Array<T>::Array(unsigned int n):Data(new T[n]()),length(n){}
template <typename T>
Array<T>::Array(const Array<T>& other):Data(nullptr),length(other.length)
{
    if(length > 0)
    {
        Data = new T[length];
        for(unsigned int i = 0; i < length;i++)
        {
            Data[i] = other.Data[i];
        }
    }
}
template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if(this != &other)
    {
        delete [] Data;
        length = other.length;
        Data = (length > 0) ? new T[length]: nullptr;
        for(unsigned int i = 0; i < length;i++)
        {
            Data[i] = other.Data[i];
        }
    }
    return *this;
}
template <typename T>

Array<T>::~Array()
{
    delete[] Data;
}
template <typename T>

T& Array<T>::operator[](unsigned int index)
{
    if(index >= length)
    {
        throw std::out_of_range("Array index out of bounds");
    }
    return Data[index];
}
template <typename T>

const T& Array<T>::operator[](unsigned int index) const
{
    if(index >= length)
    {
        throw std::out_of_range("Array index out of bounds");
    }
    return Data[index];
}
template <typename T>

unsigned int Array<T>::size() const
{
    return length;
}
