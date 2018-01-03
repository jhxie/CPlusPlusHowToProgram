#pragma once

#include <array>
#include <iostream>

template <class T, const size_t size>
void DisplayArray(const std::array<T, size> &values)
{
    for (T value : values) {
        std::cout << value << " ";
    }
    std::cout << std::endl;
}
